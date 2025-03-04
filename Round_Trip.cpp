// DNB
// C++
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define nl "\n"
#define F first
#define S second
#define vin(v,n) for(int i = 0; i<n; i++){cin>>v[i];}
#define all(v) v.begin(), v.end()
#define space " "
#define int long long int
 
using namespace std;
typedef int ll;
vector<int>loop;

void printCycle(int start, int node, const vector<int>& par) {
    vector<int> cycle;
    
    int cur = node;
    cycle.push_back(start);
    cycle.push_back(cur);
    while(cur != start) {
        cur = par[cur];
        cycle.push_back(cur);
    }
    
    reverse(cycle.begin(), cycle.end());
    cout << cycle.size() << nl;
    for (auto v : cycle) cout << v << " ";
    cout << nl;
}

bool dfs(int node, int parent, vector<int>& par, vector<vector<int>>& adj) {
    par[node] = parent; 
    for (auto neighbor : adj[node]) {
        if (neighbor == parent) continue; 
        if (par[neighbor] != -1) {

            printCycle(neighbor, node, par);
            return true;
        }
        if (dfs(neighbor, node, par, adj)) return true;
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> par(n+1, -1);
    
    for (int i = 1; i <= n; i++) {
        if (par[i] == -1) {
           
            if (dfs(i, 0, par, adj))
                return;
        }
    }
    cout << "IMPOSSIBLE" << nl;
}


signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t =1;
//   cin>>t;
  while(t--){
    solve();


  }
  return 0;
}