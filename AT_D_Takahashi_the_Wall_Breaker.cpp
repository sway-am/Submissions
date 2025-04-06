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
#define INF (ll)1e+15
const int MOD = 998244353;

 
using namespace std;
typedef int ll;
/*
    Direct Dijsktra 
*/
   
typedef pair<int, pair<int, int>> Node;          // {cost, {row, col}}

vector<pair<int, int>> mov = {{0,1}, {1,0}, {-1,0}, {0,-1}};

void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (int i = 0; i < h; i++) cin >> grid[i];

    int x, y, fx, fy;
    cin >> x >> y >> fx >> fy;
    x--; y--; fx--; fy--;

    vector<vector<int>> dist(h, vector<int>(w, INF));
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    dist[x][y] = 0;
    pq.push({0, {x, y}});

    while (!pq.empty()) {
        auto [cost, pos] = pq.top(); pq.pop();
        auto [r, c] = pos;

        if (r == fx && c == fy) {
            cout << cost << nl;
            return;
        }

        if (dist[r][c] < cost) continue; 

       
        for (auto [dx, dy] : mov) {
            int nr = r + dx, nc = c + dy;
            if (nr < 0 || nc < 0 || nr >= h || nc >= w) continue;
            if (grid[nr][nc] == '#') continue;
            if (dist[nr][nc] > dist[r][c]) {
                dist[nr][nc] = dist[r][c];
                pq.push({dist[nr][nc], {nr, nc}});
            }
        }

        
        for (auto [dx, dy] : mov) {
            for (int step = 1; step <= 2; step++) {
                int nr = r + dx * step, nc = c + dy * step;
                if (nr < 0 || nc < 0 || nr >= h || nc >= w) break;
                if (dist[nr][nc] > dist[r][c] + 1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }
    }

    cout << -1 << nl;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
//   cin>>t;
  while(t--){
    solve();


  }
  return 0;
}