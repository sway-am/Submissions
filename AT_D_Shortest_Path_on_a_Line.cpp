#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

// Structure for an edge in the graph.
struct Edge {
    int to;
    ll w;
};

//
// We build two segment trees: one for "range to vertex" (inTree)
// and one for "vertex to range" (outTree). We use a standard 1-indexed
// segment tree structure. In our combined graph, the nodes will be assigned
// new vertex IDs as follows:
//   - Actual vertices: 1 .. N
//   - OutTree nodes: assigned IDs outBase .. outBase + (2*segSize - 1) - 1
//   - InTree nodes: assigned IDs inBase .. inBase + (2*segSize - 1) - 1
//   - Auxiliary (operation) vertices: opBase .. opBase + M - 1
//

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    // Store operations: for each op, L, R, C.
    vector<int> L(M), R(M);
    vector<ll> C(M);
    for (int i = 0; i < M; i++){
        cin >> L[i] >> R[i] >> C[i];
    }
    
    // Build segment tree size (power of 2 >= N).
    int segSize = 1;
    while(segSize < N) segSize *= 2;
    
    // Count nodes in each segment tree:
    int outTreeCount = 2 * segSize - 1;
    int inTreeCount  = 2 * segSize - 1;
    
    // Determine vertex id bases.
    // Actual vertices: 1 ... N.
    int actualBase = 1;
    int nextId = N + 1;
    int outBase = nextId; nextId += outTreeCount;
    int inBase  = nextId; nextId += inTreeCount;
    int opBase  = nextId; nextId += M;
    
    int totalV = nextId - 1;
    
    // Build graph as an adjacency list.
    vector<vector<Edge>> graph(totalV + 1);
    
    // Helper lambda to add a directed edge.
    auto add_edge = [&](int u, int v, ll w) {
        graph[u].push_back({v, w});
    };
    
    // --- Build OutTree --- 
    // (This tree will be used to simulate edges from an auxiliary vertex to all actual vertices in an interval.)
    // We consider a 1-indexed segment tree over indices [1, segSize].
    // Leaves corresponding to actual vertices: indices segSize ... segSize+N-1.
    for (int i = 1; i < segSize; i++) {
        int u = outBase + i - 1;
        int lc = outBase + 2*i - 1, rc = outBase + 2*i; 
        // edge from internal node to left and right child (weight 0)
        add_edge(u, lc, 0);
        add_edge(u, rc, 0);
    }
    // Connect leaves to the actual vertices.
    for (int i = segSize; i < segSize + N; i++){
        int u = outBase + i - 1;
        int v = i - segSize + 1; // actual vertex number
        add_edge(u, v, 0);
    }
    // (For leaves corresponding to indices > N we do nothing.)
    
    // --- Build InTree ---
    // (This tree will be used to simulate edges from actual vertices in an interval to an auxiliary vertex.)
    // In this tree we “collect” from actual vertices. We add edges from an actual vertex to its corresponding leaf,
    // and then from a leaf to its parent.
    for (int i = segSize; i < segSize + N; i++){
        int v = i - segSize + 1; // actual vertex
        int u = inBase + i - 1;
        add_edge(v, u, 0);
    }
    for (int i = segSize - 1; i >= 1; i--){
        int u = inBase + i - 1;
        int lc = inBase + 2*i - 1, rc = inBase + 2*i;
        // edge from children to parent (weight 0)
        add_edge(lc, u, 0);
        add_edge(rc, u, 0);
    }
    
    // --- Add edges corresponding to operations ---
    // For each operation op (with index j from 0 to M-1) and parameters L, R, C:
    //  - from every actual vertex in [L,R] we add an edge (via the InTree) to op with weight 0.
    //  - from op we add an edge (via the OutTree) to every actual vertex in [L,R] with weight C.
    //
    // We add these edges by “querying” the segment tree. In a standard segment tree query,
    // we find the minimal set of nodes covering the interval [L, R].
    
    auto add_range_inEdge = [&](int Lq, int Rq, int opVertex) {
        // InTree leaves are at indices: [segSize, segSize+N-1] (1-indexed tree indices)
        int l = Lq + segSize - 1;
        int r = Rq + segSize - 1;
        while(l <= r){
            if(l % 2 == 1){
                int node = inBase + l - 1;
                add_edge(node, opVertex, 0);
                l++;
            }
            if(r % 2 == 0){
                int node = inBase + r - 1;
                add_edge(node, opVertex, 0);
                r--;
            }
            l /= 2; r /= 2;
        }
    };
    
    auto add_range_outEdge = [&](int Lq, int Rq, int opVertex, ll cost) {
        int l = Lq + segSize - 1;
        int r = Rq + segSize - 1;
        while(l <= r){
            if(l % 2 == 1){
                int node = outBase + l - 1;
                add_edge(opVertex, node, cost);
                l++;
            }
            if(r % 2 == 0){
                int node = outBase + r - 1;
                add_edge(opVertex, node, cost);
                r--;
            }
            l /= 2; r /= 2;
        }
    };
    
    // For each operation j (0-indexed), its vertex id is opBase + j.
    for (int j = 0; j < M; j++){
        int opVertex = opBase + j;
        // From range [L[j], R[j]] in InTree to opVertex with weight 0.
        add_range_inEdge(L[j], R[j], opVertex);
        // From opVertex to range [L[j], R[j]] in OutTree with weight C[j].
        add_range_outEdge(L[j], R[j], opVertex, C[j]);
    }
    
    // --- Run Dijkstra from actual vertex 1 to actual vertex N ---
    vector<ll> dist(totalV+1, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    
    auto relax = [&](int v, ll d) {
        if(d < dist[v]){
            dist[v] = d;
            pq.push({d, v});
        }
    };
    
    relax(1, 0);
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(d != dist[u]) continue;
        for(auto &e: graph[u]){
            if(dist[e.to] > d + e.w){
                relax(e.to, d + e.w);
            }
        }
    }
    
    ll ans = dist[N];
    if(ans == INF) ans = -1;
    cout << ans << "\n";
    return 0;
}
