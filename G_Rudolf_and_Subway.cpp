// DNB
//C++
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define int long long
const int INF = 1e9;
/*
    INstead of offset, just used next nodes
*/
 
void solve() {
    int n, m;
    cin >> n >> m;

    map<int, int> colorToNode;
    int virtualIndex = n + 1;

    vector<vector<int>> adj(n + m + 10);  
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        if (!colorToNode.count(w)) {
            colorToNode[w] = virtualIndex++;
        }
        int virtualNode = colorToNode[w];

        adj[u].push_back(virtualNode);
        adj[virtualNode].push_back(u);
        adj[v].push_back(virtualNode);
        adj[virtualNode].push_back(v);
    }

    int s, e;
    cin >> s >> e;

    if (s == e) {
        cout << 0 << nl;
        return;
    }

    vector<int> dist(virtualIndex, INF);  
    dist[s] = 0;
    deque<int>dq;
    dq.push_front(s);

    // 0-1 BFS
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();

        for (int v : adj[u]) {
            int cost = (v > n) ? 0 : 1;  
            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                if (cost == 0)
                    dq.push_front(v);
                else
                    dq.push_back(v);
            }
        }
    }

    int ans = dist[e];
    cout << (ans == INF ? -1 : ans) << nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
