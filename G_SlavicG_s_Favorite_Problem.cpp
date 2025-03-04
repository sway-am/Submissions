// DNB
// C++
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define nl "\n"
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define int long long int
 
using namespace std;
typedef int ll;
 
/*
  BFS based soltuion wont work as when doing dfs1, we must ignore 
  all the XORs on the path from a->b which was not happening 
*/
void dfs1(int u, int par, int x, int b, const vector<vector<pair<int, int>>>& v, set<int>& st) {
    if(u == b) return; 
    st.insert(x);
    for(auto &edge : v[u]) {
        int nex = edge.first, w = edge.second;
        if(nex == par) continue;
        dfs1(nex, u, x ^ w, b, v, st);
    }
}
 

bool dfs2(int u, int par, int x, int b, const vector<vector<pair<int, int>>>& v, const set<int>& st) {
    if(u != b && st.count(x)) return true;
    for(auto &edge : v[u]) {
        int nex = edge.first, w = edge.second;
        if(nex == par) continue;
        if(dfs2(nex, u, x ^ w, b, v, st)) return true;
    }
    return false;
}
 
void solve()
{
  int n, a, b; 
  cin >> n >> a >> b;
  vector<vector<pair<int, int>>> v(n+1);
 
  for(int i = 0; i < n-1; i++)
  {
    int x, y, w;
    cin >> x >> y >> w;
    v[x].push_back({y, w});
    v[y].push_back({x, w});
  }
 
  set<int> st;
  dfs1(a, -1, 0, b, v, st);
  
  if(dfs2(b, -1, 0, b, v, st))
    cout << "YES" << nl;
  else 
    cout << "NO" << nl;
}
 
signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
