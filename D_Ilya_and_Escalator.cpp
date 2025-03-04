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
/*
    Basically a probability problem, direct maths, no further explanation required.
*/


void solve()
{
    cout<<setprecision(7)<<nl;
    ll n, t;
    double p;

    cin>>n>>p>>t;

    vector<vector<double>> dp(t+1, vector<double>(n+1, 0));

    dp[1][0]= 1-p;

    dp[1][1] = p;

    for(int i = 2; i <= t; i++)
    {
        for(int j = 0; j <= min(n, t); j++)
        {
            if(j == 0)
            {
                dp[i][j] = dp[i-1][j]*(1-p);
                continue;
            }

            if(j == n)
            {
                dp[i][j] = dp[i-1][j ] + dp[i-1][j-1]*p;
                continue;
            }

            dp[i][j] = dp[i-1][j]*(1-p) + dp[i-1][j-1]*p;
        }
    }


    double ans= 0;
    for(int i = 0; i<= min(t, n); i++)
    {
        ans += i*dp[t][i];
    }

    cout<<ans<<endl;






}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t  =1 ;
//   cin>>t;
  while(t--){
    solve();


  }
  return 0;
}