// DNB
// C++ 
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define nl "\n"
#define F first
#define S second
#define vin(v, n) for (int i = 0; i < n; i++) { cin >> v[i]; }
#define all(v) v.begin(), v.end()
#define space " "
#define int long long int

using namespace std;
typedef int ll;

/*
  - Each node represents a player.
  - Start with a player as crewmate (1) and propagate using BFS/DFS.
  - If any contradiction is found, return -1.
  - Count `crewmates` and `imposters` separately and take the maximum.

  Note how i created a undirected graph, this is because if u notice 
  the edge weigit is bidiretional ie

  1 2 -1 means

  if 1 is c 2 must be i
  if 2 is i 1 must be c

  if 2 is c 1 must be i
  if 1 is i 2 must be c

  crete bidir graph
*/

pair<int, int> bfs(int node, vector<vector<pair<int, int>>>& adj, vector<int>& color) {
    queue<int> q;
    q.push(node);
    color[node] = 1; 

    int crw = 0, imp = 0; 
    
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        
        if (color[n] == 1) crw++; 
        else imp++;

        for (auto it : adj[n]) {
            int x = it.first;
            int w = it.second;
            int new_color = color[n] * w;

            if (color[x] == 0) { 
                color[x] = new_color;
                q.push(x);
            } 
            else if (color[x] != new_color) {  
                return {-1, -1};  
            }
        }
    }

    return {crw, imp};
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        string s;
        cin >> u >> v >> s;

        if (s == "imposter") {
            adj[u].push_back({v, -1});
            adj[v].push_back({u, -1});
        } else {
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 1});
        }
    }

    vector<int> color(n + 1, 0);  
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {  
            auto res = bfs(i, adj, color);

            if (res.first == -1) {
                cout << -1 << nl;  
                return;
            }
            ans += max(res.first, res.second);
        }
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
