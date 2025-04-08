#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//-----------------------//
/*
    BINARY LIFTING

    used to find the LCA for Q queries in 
    NlogN + QlogN 
    basically precompyte in NlogN

    then logN for every query
*/

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}
//--------------/ DFS for graph
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];
void dfs(int vertex)
{
    /** Take action on vertex
     * after entering the vertex**/
    if (vis[vertex])
        return;
    vis[vertex] = true;
    for (int child : g[vertex])
    {
        /*Take action on child before
        entering the child node*/
        // if(vis[child]) continue;
        dfs(child);
        /*TAke action on child
        after exiting child node*/
    }
    /*Take action on vertex before
    exiting the vertex*/
} // O(vertices+edges)
int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    for (int i = 0; i < edges; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    int cnt = 0;
    for (int i = 1; i <= vertex; i++)
    {
        if (vis[i])
            continue;
        dfs(i);
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
//----------------------------------------------------------------
// DFS for tree to find height and depth of nodes
// no need of visited array instead pass the parent
const int N = 1e5 + 10;
vector<int> g[N];
int depth[N], height[N];

void dfs_tree(int vertex, int parent = 0)
{
    /** Take action on vertex
     * after entering the vertex**/

    for (int child : g[vertex])
    {
        /*Take action on child before
        entering the child node*/
        // if(vis[child]) continue;
        if (child == parent)
            continue;
        depth[child] = depth[vertex] + 1;
        dfs_tree(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
        /*TAke action on child
        after exiting child node*/
    }
    /*Take action on vertex before
    exiting the vertex*/
}
int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    for (int i = 0; i < edges; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs_tree(1);
    return 0;
}
//----------------------------------------------------------------
// diameter of a tree in O(vertex) time complexity
const int N = 1e5 + 10;
vector<int> g[N];
int depth[N];
void dfs_tree(int v, int par = -1)
{
    for (int child : g[v])
    {
        if (child == par)
            continue;
        depth[child] = depth[v] + 1;
        dfs_tree(child, v);
    }
}

int main()
{

    int vertex, edges;
    cin >> vertex >> edges;
    for (int i = 0; i < edges; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs_tree(1);
    int max_depth = -1;
    int max_depth_node;
    for (int i = 1; i <= vertex; i++)
    {
        if (max_depth < depth[i])
        {
            max_depth = depth[i];
            max_depth_node = i;
        }
        depth[i] = 0; // for running dfs again
    }
    dfs_tree(max_depth_node);
    max_depth = -1;
    for (int i = 1; i <= vertex; i++)
    {
        if (max_depth < depth[i])
        {
            max_depth = depth[i];
            max_depth_node = i;
        }
    }
    cout << max_depth << endl;
    return 0;
}
//----------------------------------------------------------------
// Lowest common ancestor(LCA) in O(N) in a tree
// and path of a vertex from root node
const int N = 1e5 + 10;
vector<int> g[N];
int par[N];
void dfs_tree(int vertex, int parent = -1)
{
    par[vertex] = parent;
    for (int child : g[vertex])
    {
        if (child == parent)
            continue;
        dfs_tree(child, vertex);
    }
}
vector<int> path(int vertex)
{
    vector<int> ans;
    while (vertex != -1)
    {
        ans.push_back(vertex);
        vertex = par[vertex];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs_tree(1);
    int x, y;
    cin >> x >> y;
    vector<int> path_x = path(x);
    vector<int> path_y = path(y);
    int min_length = min(path_x.size(), path_y.size());

    int lca = -1;
    for (int i = 0; i < min_length; i++)
    {
        if (path_x[i] == path_y[i])
        {
            lca = path_x[i];
        }
        else
        {
            break;
        }
    }
    cout << lca << endl;
    return 0;
}
//----------------------------------------------------------------
// breadth first serach (BFS) algorithm
// used for finding shortest path between nodes
// if weights of edges have equal weights
const int N = 1e5 + 10;
vector<int> g[N];
int vis[N];
int level[N];
void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    while (!q.empty())
    {
        int current_vertex = q.front();
        q.pop();

        for (int child : g[current_vertex])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
                level[child] = level[current_vertex] + 1;
            }
        }
    }
}
// time complexity O(vertex + edges)

int main()
{
    int edges;
    cin >> edges;
    for (int i = 0; i < edges; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);
}
//----------------------------------------------------------------
// dijkstra algorithm on weighted graphs (directed and undirected both)
// time complexity is O(V + Elog(V))
// used for finding the shortest distance between nodes in a weighted graph
#include <iostream>
#include <bits/stdc++.h>
const int N = 1e3 + 10;
const int INF = 1e9 + 10;
vector<pair<int, int>> g[N]; // (node,weight)

void dijkstra(int source)
{
    vector<int> vis(N, 0);
    vector<int> dist(N, INF);

    set<pair<int, int>> st; // (distance , node) sorted on the basis of distance
    st.insert({0, source});
    dist[source] = 0;
    while (st.size() > 0)
    {
        auto node = *st.begin();
        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());
        if (vis[v] == 1)
            continue;
        vis[v] = 1;
        for (auto child : g[v])
        {
            int child_v = child.first;
            int wt = child.second;
            if (dist[v] + wt < dist[child_v])
            {
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
}
int main()
{
    int vertex, edges;
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        int wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt});
    }
}
//----------------------------------------------------------------
// Bellman ford Algorithm
// helps you to detect negative cycles as well
// applicaple only for directed graphs
// convert undirected graphs into directed ones in order to apply bellman fords algo
// N-1 iterations becuase worst case is N-1
// to check negative cycles run the algo Nthe time if update occurs them negative cycle is present
// time complexity is O(V*E)
vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    // Code here
    vector<int> dis(V, 1e8);
    dis[S] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dis[u] != 1e8 && dis[u] + wt < dis[v])
            {
                dis[v] = dis[u] + wt;
            }
        }
    }
    // Nt iteration to check negative cycle
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dis[u] != 1e8 && dis[u] + wt < dis[v])
        {
            return {-1};
        }
    }
    return dis;
}
//----------------------------------------------------------------
// Floyd Warshall algorithm
// multisource source shortest path algo
// all pair shortest paths in weighted graphs
// handles -ve weights of edges
// does not handle -ve weighted cycles
// O(N^3)
// if dis[v][v]<0 means a negative cycle
const int N = 510;
const int INF = 1e9 + 10;
int dist[N][N];
int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else
            {
                dist[i][j] = INF;
            }
        }
    }
    int n, m; // vertex, edges
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x, y, wt;
            cin >> x >> y >> wt;
            dist[x][y] = wt;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
                // dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    // for negative cycles present or not
    for (int i = 0; i < V; i++)
    {
        if (dist[i][i] < 0)
        {
            return true;
        }
    }
}

//----------------------------------------------------------------
// Bipartiti Graph --> adjacent node are of different color
bool dfs(vector<int> adj[], vector<int> &vis, int node, int color)
{
    vis[node] = 1 + color;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (!dfs(adj, vis, it, 1 - color))
            {
                return false;
            }
        }
        else if (vis[it] == vis[node])
        {
            // cout<<"haha"<<it<<endl;
            return false;
        }
    }
    return true;
}
bool isBipartite(int V, vector<int> adj[])
{
    // Code here
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (!dfs(adj, vis, i, 0))
            {
                return false;
            }
        }
    }
    return true;
}
//----------------------------------------------------------------
// cycle detection in Directed Acyclic Graph (DG)
// Kahn's algorithm(BFS) && Topological Sort(exists only for DAGs)
// O(V+E)
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<int> topo;
    queue<int> q;
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (!indegree[i])
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
        topo.push_back(node);
    }
    if (topo.size() == V)
    {
        return false;
    }
    else
    {
        return true;
    }
}
//----------------------------------------------------------------
// topo sort using dfs
void dfs(vector<int> adj[], vector<int> &vis, stack<int> &st, int node)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(adj, vis, st, it);
        }
    }
    st.push(node);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<int> ans;
    stack<int> st;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(adj, vis, st, i);
        }
    }
    for (int i = 0; i < V; i++)
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
//----------------------------------------------------------------
// cycle detection in Dag's using DFS (path_vis array)
bool dfs(vector<int> adj[], vector<int> &vis, vector<int> &path_vis, int node, vector<int> &ans)
{
    vis[node] = 1;
    path_vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (!dfs(adj, vis, path_vis, it, ans))
            {
                return false;
            }
        }
        else if (path_vis[it])
        {
            return false;
        }
    }
    path_vis[node] = 0;
    ans.push_back(node);
    return true;
}
vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    // code here
    vector<int> ans;
    vector<int> vis(V, 0);
    vector<int> path_vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            bool yes = dfs(adj, vis, path_vis, i, ans);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
//----------------------------------------------------------------
// Prims' algo to find weight of minimum spanning tree
// and the edges of minimun spanning tree
// based on greedy approach
// 2*E*log(E) which is E*logE
int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    vector<int> vis(V, 0);
    set<pair<int, int>> s;
    int sum = 0;
    // intitial condition to start the algo
    s.insert({0, 0}); // {wt,node}
    while (!s.empty())
    {
        int node = s.begin()->second;
        int wt = s.begin()->first;
        s.erase(s.begin());
        if (vis[node])
            continue;
        vis[node] = 1;
        sum += wt;
        for (auto it : adj[node])
        {
            int child = it[0];
            int wt_child = it[1];
            if (!vis[child])
            {
                s.insert({wt_child, child});
            }
        }
    }
    return sum;
}

// for full tree
vector<vector<int>> SpanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    vector<vector<int>> tree(V);
    vector<int> vis(V, 0);
    set<pair<int, pair<int, int>>> s;
    int sum = 0;
    // intitial condition to start the algo
    s.insert({0, {0, -1}}); // {wt,{node,parent}}
    while (!s.empty())
    {
        int node = s.begin()->second.first;
        int parent = s.begin()->second.second;
        int wt = s.begin()->first;
        s.erase(s.begin());
        if (vis[node])
            continue;
        vis[node] = 1;
        sum += wt;
        tree[node].push_back(parent);
        tree[parent].push_back(node);
        for (auto it : adj[node])
        {
            int child = it[0];
            int wt_child = it[1];
            if (!vis[child])
            {
                s.insert({wt_child, {child, node}});
            }
        }
    }
    return tree;
}
//----------------------------------------------------------------
// Disjoint set Class
// O(4*alpha) alpha-->1 hence constant time complexity
// to find if 2 given nodes belong to the same component or not
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main()
{
    DisjointSet ds1(7), ds2(5);
    ds1.unionByRank(1, 2);
    ds1.unionByRank(2, 3);

    if (ds1.findUPar(3) == ds1.findUPar(7))
    {
        // same
    }
    else
    {
        // not same
    }
}

//----------------------------------------------------------------
// Kruskals algorithm
// uses Dijoint set
// O(V+E) + O(Elog E)+ O(E*4*alpha * 2)
int main()
{
    vector<pair<int, pair<int, int>>> edges;
    // O(V+E)
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            int adjnode = it[0];
            int wt = it[1];
            int node = i;
            edges.push_back({wt, {node, adjnode}});
        }
    }
    // O(ElogE)
    sort(edges.begin(), edges.end()); // very important step !!!!
    DisjointSet ds(V);
    int mst_wt = 0;
    // O(E*4*alpha * 2)
    for (auto it : edges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if (ds.findUPar(u) != ds.findUPar(v))
        {
            mst_wt += wt;
            ds.unionBySize(u, v);
        }
    }
}
//----------------------------------------------------------------
// Bridges in a graph
// Tarjan's algo based in lowes time and insertion time
// modified dfs
// O(V+2*E)==> time complexity of dfs traversal
int timer = 1;
void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges)
{
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!vis[it])
        {
            dfs(it, node, vis, adj, tin, low, bridges);
            low[node] = min(low[node], low[it]);
            if (low[it] > tin[node])
            {
                bridges.push_back({it, node});
            }
        }
        else
        {
            low[node] = min(low[node], low[it]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<int> adj[n];
    for (auto it : connections)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(n, 0);
    int tin[n];
    int low[n];
    vector<vector<int>> bridges;
    dfs(0, -1, vis, adj, tin, low, bridges);
    return bridges;
}
//----------------------------------------------------------------
// articulation points in a graph
int timer = 0;
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> &mark, vector<int> adj[])
{
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    int child = 0;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!vis[it])
        {
            dfs(it, node, vis, tin, low, mark, adj);
            low[node] = min(low[node], low[it]);
            if (low[it] >= tin[node] and parent != -1)
            {
                mark[node] = 1;
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }
    if (child > 1 and parent == -1)
    {
        mark[node] = 1;
    }
}

vector<int> articulationPoints(int n, vector<int> adj[])
{
    // Code here
    vector<int> vis(n, 0);
    vector<int> tin(n);
    vector<int> low(n);
    vector<int> mark(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, vis, tin, low, mark, adj);
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (mark[i])
            ans.push_back(i);
    }
    if (ans.size() == 0)
        return {-1};
    else
        return ans;
}
//----------------------------------------------------------------
// Kosraju's algorithm to find strongly connected components
// strongly connected components are only in directed graphs
// 1) sort all the edges by finishing time
// 2) reverse the graph
// 3) do dfs
// TC = 3*O(V+E)
void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, st, adj);
        }
    }
    st.push(node);
}
void dfs2(int node, vector<int> adjT[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adjT[node])
    {
        if (!vis[it])
        {
            dfs2(it, adjT, vis);
        }
    }
}

// Function to find number of strongly connected components in the graph.
int kosaraju(int V, vector<vector<int>> &adj)
{
    stack<int> st;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }
    vector<int> adjT[V];
    for (int i = 0; i < V; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }
    int scc = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            scc++;
            dfs2(node, adjT, vis);
        }
    }

    return scc;
}

//----------------------------------------------------------------
// BINARY EXPONENTIATION
int BinaryExp(int c, int d, int m)
{
    c %= m;
    int ans = 1;
    while (d > 0)
    {
        if (d & 1)
        {
            ans = (ans * 1LL * c) % m;
        }
        c = (c * 1LL * c) % m;
        d >>= 1;
    }
    return ans;
}
// ----------------------------------------------------------------//
// BINARY SERACH
int Binarysearch(vector<int> &v, int key)
{
    int lo = 0;
    int hi = v.size() - 1;
    int mid = lo + (hi - lo) / 2;
    while (hi - lo > 1)
    {
        mid = lo + (hi - lo) / 2;
        if (v[mid] < key)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    if (v[lo] == key)
    {
        return lo;
    }
    else if (v[hi] == key)
    {
        return hi;
    }
    return -1;
}
// ----------------------------------------------------------------
// finding prime the in O(root(N))
// based on the fact that any composite number has at
// least one prime between 1 & root N.

vector<int> ans;
for (int i = 2; i * i <= N; i++)
{
    while (N % i == 0)
    {
        ans.push_back(i);
        N /= i;
    }
}
if (N != 1)
{
    ans.push_back(N);
}
return ans;
// SIEVE Algo to find primes Time complexity = N* log(log(N))
const int N = 1e7 + 10;
vector<bool> isPrime(N, 1);
vector<int> lp(N), hp(N);

int main()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            lp[i] = hp[i] = i;
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
                hp[j] = i;
                if (lp[j] == 0)
                {
                    lp[j] = i;
                }
            }
        }
    }
    // prime factors in log (N)
    int num;
    cin >> num;
    vector<int> prime_factors;
    unordered_map<int, int> m;
    while (num > 1)
    {
        int prime_factor = hp[num];
        while (num % prime_factor == 0)
        {
            num /= prime_factor;
            prime_factors.push_back(prime_factor);
            m[prime_factor]++;
        }
    }
    // prime factors in log (N)
}

//----------------------------------------------------------------
// kadanes algo to find max subarry sum
int kadanesAlgorithm(const std::vector<int> &arr)
{
    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < arr.size(); ++i)
    {
        currentSum += arr[i];

        // Update the maximum sum if the current sum is greater
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
        }
        // If the current sum becomes negative, reset it to 0
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }

    return maxSum;
}
//----------------------------------------------------------------
// Least recently used algorithm (one of Page replacement algorithms)
// Function to find page faults using indexes
int pageFaults(int pages[], int n, int capacity)
{
    // To represent set of current pages. We use
    // an unordered_set so that we quickly check
    // if a page is present in set or not
    unordered_set<int> s;

    // To store least recently used indexes
    // of pages.
    unordered_map<int, int> indexes;

    // Start from initial page
    int page_faults = 0;
    for (int i = 0; i < n; i++)
    {
        // Check if the set can hold more pages
        if (s.size() < capacity)
        {
            // Insert it into set if not present
            // already which represents page fault
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);

                // increment page fault
                page_faults++;
            }

            // Store the recently used index of
            // each page
            indexes[pages[i]] = i;
        }

        // If the set is full then need to perform lru
        // i.e. remove the least recently used page
        // and insert the current page
        else
        {
            // Check if current page is not already
            // present in the set
            if (s.find(pages[i]) == s.end())
            {
                // Find the least recently used pages
                // that is present in the set
                int lru = INT_MAX, val;
                for (auto it = s.begin(); it != s.end(); it++)
                {
                    if (indexes[*it] < lru)
                    {
                        lru = indexes[*it];
                        val = *it;
                    }
                }

                // Remove the indexes page
                s.erase(val);

                // insert the current page
                s.insert(pages[i]);

                // Increment page faults
                page_faults++;
            }

            // Update the current page index
            indexes[pages[i]] = i;
        }
    }

    return page_faults;
}
//----------------------------------------------------------------
// Manachers algo O(N)
// getLongest palindrome for a given index in O(1)
// check palindrome in L to r in O(1)

void manacher(string &s)
{
    string t = "";
    for (int i = 0; i < s.length(); i++)
    {
        t += "#";
        t += s[i];
    }
    t += "#";
    int n = t.length();
    vector<int> p(n, 1);
    int l = 0, r = 2;
    for (int i = 1; i < n; i++)
    {
        if (l + r - i < n && l + r - i >= n)
        {
            p[i] = max(0, min(r - i, p[l + r - i]));
        }
        while (i + p[i] < n && i - p[i] >= 0 && t[i + p[i]] == t[i - p[i]])
        {
            p[i]++;
        }
        if (i + p[i] > r)
        {
            l = i - p[i];
            r = i + p[i];
        }
    }
    // get longest palindrome with given center
    // check if center is odd or even
    //->> getlongest
    int pos = 2 * cen + 1 + (!odd);
    int ans = p[pos] - 1;
    // check palindrome in given l and r
    if ((r - l + 1) <= getlongest((l + r) / 2, l % 2 == r % 2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//----------------------------------------------------------------
// Dealing with large nCr --Codeforces
int power_mod(int a, int n, int p)
{
    int res = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            res = (res * a) % p;
            n--;
        }
        else
        {
            a = (a * a) % p;
            n /= 2;
        }
    }
    return res;
}
const int N = 2e5 + 5;
int fact[N];
int nCr(int n, int k)
{
    if (n < k)
        return 0LL;
    return (fact[n] * power_mod((fact[n - k] * fact[k]) % mod, mod - 2, mod)) % mod;
}

//----------------------------------------------------------------
// #include <atcoder/all>
using namespace atcoder;

constexpr ll mod = 998244353;
using mint = static_modint<mod>;

vector<mint> fac, inv, facinv;

void modcalc(int n = 3000)
{
    fac.resize(n);
    inv.resize(n);
    facinv.resize(n);
    fac[0] = 1;
    fac[1] = 1;
    inv[1] = 1;
    facinv[0] = 1;
    facinv[1] = 1;
    for (ll i = 2; i < n; i++)
    {
        fac[i] = fac[i - 1] * i;
        inv[i] = -inv[mod % i] * (mod / i);
        facinv[i] = facinv[i - 1] * inv[i];
    }
}

mint nCr(int n, int k)
{
    if (n < 0 || k < 0 || n < k)
        return 0;
    return fac[n] * facinv[k] * facinv[n - k];
}

//----------------------------------------------------------------
// mint technique of atcoder
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;

// Define modint type with the specified modulo
using mint = modint1000000007;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    mint ans = 1;
    mint temp = 1;

    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
        {
            temp += 1;
        }
        else
        {
            if (temp.val() % 2 == 1)
            {
                temp += 1;
            }
            ans *= temp * mint(2).inv();
            temp = 1;
        }
    }
    if (temp != 1)
    {
        if (temp.val() % 2 == 1)
        {
            temp += 1;
        }
        ans *= temp * mint(2).inv();
    }
    cout << ans.val() << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
--------------------------------------------------------
// Some properties of bitwise operations:
// a|b = a⊕b + a&b
// a⊕(a&b) = (a|b)⊕b
// b⊕(a&b) = (a|b)⊕a
// (a&b)⊕(a|b) = a⊕b
// Addition:
// a+b = a|b + a&b
// a+b = a⊕b + 2(a&b)
// Subtraction:
// a-b = (a⊕(a&b))-((a|b)⊕a)
// a-b = ((a|b)⊕b)-((a|b)⊕a)
// a-b = (a⊕(a&b))-(b⊕(a&b))
// a-b = ((a|b)⊕b)-(b⊕(a&b))