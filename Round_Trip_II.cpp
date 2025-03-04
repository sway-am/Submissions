// DNB
// C++
// Faster input-output optimizations
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define nl "\n"
#define F first
#define S second
#define vin(v,n) for(int i = 0; i < n; i++) { cin >> v[i]; }
#define all(v) v.begin(), v.end()
#define space " "
#define int long long int

using namespace std;
typedef int ll;

void printCycle(int start, int node, const vector<int>& par) {
    vector<int> cycle;
    int cur = node;
    cycle.push_back(start);
    cycle.push_back(cur);
    while (cur != start) {
        cur = par[cur];
        cycle.push_back(cur);
    }
    reverse(cycle.begin(), cycle.end());
    cout << cycle.size() << nl;
    for (auto v : cycle) cout << v << " ";
    cout << nl;
}

bool dfs(int node, vector<int>& par, vector<int>& visited, vector<vector<int>>& adj) {
    visited[node] = 1;  // Mark node as visiting (part of recursion stack)
    for (auto neighbor : adj[node]) {
        if (visited[neighbor] == 2) continue; // Already fully processed, skip
        if (visited[neighbor] == 1) {  
            // Found a cycle
            printCycle(neighbor, node, par);
            return true;
        }
        par[neighbor] = node;
        if (dfs(neighbor, par, visited, adj)) return true;
    }
    visited[node] = 2; // Mark as fully processed
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> par(n + 1, -1);
    vector<int> visited(n + 1, 0); // 0 = unvisited, 1 = visiting, 2 = visited

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            if (dfs(i, par, visited, adj))
                return;
        }
    }
    cout << "IMPOSSIBLE" << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
