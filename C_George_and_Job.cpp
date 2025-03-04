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
ll dfs(vector<ll>& v, int ind, int m, int k, vector<vector<int>>& dp)
{
    
    if(k == 0)
    {
        return 0;
    }
    int n = v.size();
    if(ind > n-m)
    {
        return LLONG_MIN;
    }

    if(dp[ind][k] != -1)
    {
        return dp[ind][k];
    }

    int s = 0;
    for(int i = ind; i< ind + m; i++)
    {
        s += v[i];
    }

    return dp[ind][k] = max(s + dfs(v, ind + m, m, k-1, dp), dfs(v, ind+1, m, k, dp));
}


void solve()
{
    ll n, m, k;
    cin>>n>>m>>k;
    vector<int>v(n);
    vin(v, n);
    // cout<<n<<space<<m<<space<<k<<nl;
    // v, ind, m, k
    // vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
    // cout<<dfs(v, 0,m, k, dp)<<nl;


    // tabulation approach
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, LLONG_MIN));
    vector<int> prefix_sum(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + v[i];
    }
    
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0; 
    }
    
    for (int j = 1; j <= k; j++) {
        for (int i = n - m; i >= 0; i--) {
            dp[i][j] = max(prefix_sum[i + m] - prefix_sum[i] + dp[i + m][j - 1], dp[i + 1][j]);
        }
    }
    
    cout << dp[0][k] << nl;
    




}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
//   cin>>t;
  while(t--){
    solve();


  }
  return 0;
}