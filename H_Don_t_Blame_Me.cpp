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

const int MOD = 1000000000 + 7;

/*
    The maximum number can go up only to 63. So its possible to check for 
    every number that if the bitwise and of subsequences can be equal to that
    number.

    dp[i][j]
    upto first i digits how many subsequnce have bitwise and equal to j;

    1. Dont consider the current number
    2. Consider the current number
    3. start a subsequence with the current number

    ->recursive solution is also easy

    ** Some random bkchodi with MOD is happening clarify later **
*/

int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1); 
        count++;
    }
    return count;
}



void solve()
{
    ll n; cin>>n;
    ll k; cin>>k;
    vector<int>v(n);
    vin(v, n);


    // cout<<dfs(v, 0, k)<<nl;
    vector<vector<int>>dp(n+1, vector<int>(65, 0));


    for(int i = 1; i<= n; i++)
    {
        for(int j = 0; j < 64; j++)
        {
            dp[i][j] += dp[i-1][j];
            // dp[i][j] = dp[i][j] %MOD;
            if(dp[i][j] >= MOD )
                dp[i][j] -= MOD;

            dp[i][v[i-1]&j] += dp[i-1][j];
            // dp[i][v[i-1]&j] = dp[i][v[i-1]&j]%MOD;
            if(dp[i][v[i-1]&j] >= MOD)
                dp[i][v[i-1]&j] -= MOD;
        }

        dp[i][v[i-1]] += 1; 
        // dp[i][v[i-1]] = dp[i][v[i-1]]%MOD;
        if(dp[i][v[i-1]] >= MOD)
            dp[i][v[i-1]] -= MOD;
    }

    ll ans = 0;


    for(int i = 0; i < 64; i++)
    {
        if(countSetBits(i) == k)
        {
            ans = (ans +dp[n][i]%MOD);
        }
    }

    cout<<ans%MOD<<nl;


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