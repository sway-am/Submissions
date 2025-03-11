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

ll n, m;
vector<array<int, 4>> e;  
/*
    EDITORIAL WAS SEEN
    Using modified Bellman ford
    here as the ui < vi between an edge we dont need to do n-1 iternations

    b/c > = x
    b -cx >= 0

    so we can binary search on the space of x
    and get the best possile value of x
*/

bool check(double x)
{
    vector<vector<pair<int, double>>> g(n + 1);
    for (int i = 0; i < m; i++) {
        auto [u, v, b, c] = e[i];
        g[u].push_back({v, b - x * c});
    }
    vector<double> dp(n + 1, -1e18);
    dp[1] = 0;
    

    for (int u = 1; u <= n; u++) {
        if (dp[u] < -1e17) continue;
        for (auto [v, w] : g[u]) {
            dp[v] = max(dp[v], dp[u] + w);
        }
    }
    return dp[n] >= 0;
}

void solve()
{
    cin >> n >> m;
    e.resize(m);
    for (int i = 0; i < m; i++) {
        auto& [u, v, b, c] = e[i];
        cin >> u >> v >> b >> c;
    }
    double l = 0, r = 1e18;
    
    for (int _ = 0; _ < 200; _++) {
        double mid = (l + r) / 2.0;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    
    cout << fixed << setprecision(16) << l << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  while(t--){
    solve();
  }
  return 0;
}
