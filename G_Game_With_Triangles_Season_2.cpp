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
    dp[i][j] represent that we can select one vertice on i and another on j and
    k must be in between i and j.

    we can also skip vertiecs so
    dp[i][j] = max dp[i+1][j] , dp[i][j-1], dp[i+1][j-1] 

    now if we take the triangle at ijk
    dp[i][j] = ai aj ak + dp[i+1][k-1] + dp[k+1][j-1];

    if we dont take that triangle

    dp[i][j] = dp[i][k] + dp[k+1][j]

    its a MCM problem

*/


void solve()
{
    ll n; cin>>n;
    vector<int>v(2*n +1);
    for(int i = 0; i < n;i++)
    {
        cin>>v[i];
        v[i + n] = v[i];
    }
    int dp[2*n+10][2*n+10];
    memset(dp, 0, sizeof(dp));

    for(int i = 2*n-1; i >= 0; i--)
    {
        for(int j = i+ 2; j < min(2*n, i + n); j++)
        {
            
            dp[i][j] = max({dp[i+1][j], dp[i][j-1], dp[i+1][j-1], dp[i][j]});
            for(int k = i+1; k < j; k++)
            {
                int lef = 0;
                if(i + 1 <= k-1) lef = dp[i+1][k-1];
                int rig = 0;
                if(k + 1 <= j -1) rig = dp[k+1][j-1];

                dp[i][j] = max(lef + rig + v[i]*v[k]*v[j], dp[i][j]);
            }

            for(int k = i+1; k < j; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j] );
            }
        }
    }

    int ans = 0;
    for(int i = 0 ; i< 2*n; i++)
    {
        for(int j = i+2 ; j < min(2*n, i + n); j++)
        
            ans = max(ans,dp[i][j]);
        
    }

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j =0 ; j < n; j++)
    //     {
    //         cout<<dp[i][j]<<space;
    //     }cout<<nl;
    // }

    cout<<ans<<nl;


}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t =1;
  cin>>t;
  while(t--){
    solve();


  }
  return 0;
}