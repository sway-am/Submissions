#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    // For each train piece, we store the edge reversed: from A -> B becomes an edge from B to A.
    // We store: l, d, k, c, A (with stations indexed 0-based)
    vector<vector<array<int, 5>>> adj(n);
    for (int i = 0; i < m; i++){
        int l, d, k, c, A, B;
        cin >> l >> d >> k >> c >> A >> B;
        A--; B--;
        // We “reverse” the edge so that from station B we can try to update station A.
        adj[B].push_back({l, d, k, c, A});
    }
    
    // dp[u] = latest time one can depart from station u to eventually reach station N.
    // (We use 0 for "unreachable", and note that valid times are positive.)
    vector<ll> dp(n, 0);
    // For station N (index n-1), we set a very large time.
    dp[n - 1] = 2e18;
    
    // Priority queue (max-heap) for reverse Dijkstra. (pair: {current dp, station index})
    priority_queue<pair<ll, int>> pq;
    pq.push({dp[n - 1], n - 1});
    
    while(!pq.empty()){
        auto [curr, u] = pq.top();
        pq.pop();
        if (dp[u] != curr) continue;
        // For every train arriving at u, try to relax the departure station.
        for (auto &edge : adj[u]){
            int l = edge[0], d = edge[1], k = edge[2], c = edge[3], v = edge[4];
            // We can catch a train if there is some departure time t with t + c <= dp[u].
            // In particular, if dp[u] >= l + c, then we can choose an index i such that:
            //   l + i*d + c <= dp[u]
            if (curr >= (ll)l + c) {
                // Maximum number of steps we can take:
                ll steps = (curr - l - c) / d + 1;
                // We cannot take more than k trains (indices 0...k-1)
                steps = min(steps, (ll) k);
                ll candidate = l + (steps - 1) * (ll)d;
                if (candidate > dp[v]){
                    dp[v] = candidate;
                    pq.push({dp[v], v});
                }
            }
        }
    }
    
    // Output answers for stations 1..N-1 (0-indexed stations 0..n-2)
    for (int i = 0; i < n - 1; i++){
        if (dp[i] == 0) cout << "Unreachable" << "\n";
        else cout << dp[i] << "\n";
    }
    
    return 0;
}
