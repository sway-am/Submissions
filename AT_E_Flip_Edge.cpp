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

const ll INF = LLONG_MAX;
/*
  Dijsktra
*/

void solve() 
{
  int N, M, X;
  cin >> N >> M >> X;

  vector<vector<int>> adj(N + 1);
  vector<vector<int>> rev_adj(N + 1);

  for (int i = 0; i < M; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      rev_adj[v].push_back(u);
  }

  vector<vector<int>> dist(N + 1, vector<int>(2, INF));
  dist[1][0] = 0;

  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
  pq.emplace(0, 1, 0); // (distance, node, mode)

  while (!pq.empty()) {
      auto [d, node, mode] = pq.top();
      pq.pop();

      if (d > dist[node][mode]) continue;

      const auto& neighbors = (mode == 0) ? adj[node] : rev_adj[node];
      for (int next : neighbors) {
          if (dist[next][mode] > d + 1) {
              dist[next][mode] = d + 1;
              pq.emplace(d + 1, next, mode);
          }
      }

      int new_mode = 1 - mode;
      if (dist[node][new_mode] > d + X) {
          dist[node][new_mode] = d + X;
          pq.emplace(d + X, node, new_mode);
      }
  }

  int result = min(dist[N][0], dist[N][1]);
  cout << (result == INF ? -1 : result) << nl;
}


signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t =1;
  // cin>>t;
  while(t--){
    solve();


  }
  return 0;
}