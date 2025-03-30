// DNB
// C++
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define nl "\n"
#define F first
#define S second
#define int long long
using namespace std;
 
int pnt[26];       // pnt[i] holds the letter to which letter i (0-indexed) is mapped.
int f[26];         // f[i] marks if letter i appears as a target in t.
int vis[26];       // vis[i] marks if letter i has been visited in DFS.
int nd;            // nd stores the starting node for a DFS.
vector<int> g[26]; // g[i] stores the list of letters that map into letter i (reverse graph).
int ans;           // ans will accumulate the count of swap operations needed.
/*
  The transformation can be handled separately on each connected component of the graph.

For components without cycles (tree-like structures), 
the number of swap operations required is the number of edges in the component
(which equals the number of nodes minus one).

For components that form a cycle, 
an extra operation is necessary to “break” the cycle—except when the cycle 
involves all 26 letters (in which case the answer is –1).
*/
// DFS function: follow the mapping chain starting from node u.
void dfs(int u) {
    if(u < 0) return;
    
    if(vis[u]){
        
        ans += (u == nd);
        return;
    }
    vis[u] = 1;
    dfs(pnt[u]); 
}
 
void solve()
{
  int n;
  string s, t;
  cin >> n >> s >> t;


  s = " " + s;
  t = " " + t;

  nd = -1; 

  for (int i = 0; i < 26; i++){
      pnt[i] = -1;
  }


  for (int i = 1; i <= n; i++){

      if (pnt[s[i] - 'a'] != -1 && pnt[s[i] - 'a'] != t[i] - 'a'){
          cout << -1;
          return ;
      }
      pnt[s[i] - 'a'] = t[i] - 'a';
      f[t[i] - 'a'] = 1;  
  }


  int cnt = 0;
  for (int i = 0; i < 26; i++){
      cnt += f[i];
  }

  if (cnt >= 26 && s != t){
      cout << -1;
      return ;
  }


  for (int i = 0; i < 26; i++){
      if (pnt[i] == i){
          pnt[i] = -1;
      }

      // Also, build the reverse graph: for mapping i -> pnt[i], add i to g[pnt[i]].
      if (pnt[i] >= 0){
          ans++;  // Each mapping edge counts as one swap operation initially.
          g[pnt[i]].push_back(i);
      }
  }

  // First, run DFS on nodes that have at least two incoming edges.
  for (int i = 0; i < 26; i++){
    // cout<<g[i].size()<<nl;
      if (g[i].size() >= 2 && !vis[i]){
          dfs(i);
      }
  }
  // Then, for every letter not visited yet, set it as the starting node (nd) and run DFS.
  for (int i = 0; i < 26; i++){
      if (!vis[i]){
          nd = i;
          dfs(i);
      }
  }

  cout << ans;
}


 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
