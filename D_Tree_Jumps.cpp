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
const int MOD = 998244353;


void solve()
{
    int n; 
    cin >> n;
    vector<int> parent(n+1, 0);
    
    parent[1] = -1; 
    for (int i = 2; i <= n; i++){
        cin >> parent[i];
    }
 
   
    vector<int> depth(n+1, 0);

    depth[1] = 0;
    int maxi = 0;

    for (int i = 2; i <= n; i++)
    {
        depth[i] = depth[parent[i]] + 1;
        maxi = max(maxi, depth[i]);
    }
 
    
    vector<vector<int>> levs(maxi+1);
    for (int i = 1; i <= n; i++){
        levs[ depth[i] ].push_back(i);
    }
 
    
    vector<int> dp(n+1, 0);
    dp[1] = 1;
 
    
    vector<int> levlen(maxi+1, 0);
    levlen[0] = 1;
 
    
    for (int d = 1; d <= maxi; d++){
        int sumLevel = 0;
        for (int v : levs[d]) {
            int par = parent[v];
            
            if (par == 1) {
                dp[v] = levlen[d-1] % MOD;
            } else {
                dp[v] = (levlen[d-1] - dp[par] + MOD) % MOD;
            }
            sumLevel = (sumLevel + dp[v]) % MOD;
        }
        levlen[d] = sumLevel;
    }
 
    
    int ans = 0;
    for (int d = 0; d <= maxi; d++){
        ans = (ans + levlen[d]) % MOD;
    }
 
    cout << ans % MOD << nl;

}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin>>t;
  while(t--){
    solve();


  }
  return 0;
}