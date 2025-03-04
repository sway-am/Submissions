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

ll dfs(vector<ll>& dp, int ind, vector<int>& vis) {
    if (vis[ind] != 0) return vis[ind];
    if (dp[ind] == ind) return vis[ind] = 1;
    return vis[ind] = 1 + dfs(dp, dp[ind], vis);
}

void solve() {
    ll n;
    cin >> n;
    vector<int> v(n);
    vin(v, n);

    vector<int> dp(n + 1, 0);
    map<int, int> mp;

    for (int i = 1; i <= n; i++) {
        int currno = v[i - 1];
        if (mp.find(currno - 1) != mp.end()) {
            dp[i] = mp[currno - 1];
        } else {
            dp[i] = i;
        }
        mp[currno] = i;
    }

    int ans = 1;
    vector<int> vis(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0)
            dfs(dp, i, vis);
    }

    int stind = 1;
    for (int i = 1; i <= n; i++) {
        if (vis[i] > ans) {
            ans = vis[i];
            stind = i;
        }
    }

    vector<int> dis;
    while (dp[stind] != stind) {
        dis.push_back(stind);
        stind = dp[stind];
    }
    dis.push_back(stind);

    cout << ans << nl;
    sort(all(dis));
    for (auto it : dis)
        cout << it << space;
    cout << nl;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  // cin>>t;
  while(t--){
    solve();


  }
  return 0;
}