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
    Standard DP solution just use a little bit of maths
    HINT: use prefix sum to optimize
*/


void solve()
{
    ll h, w, d; cin>>h>>w>>d;
    vector<string>grid(h);
    for(int i = 0; i< h; i++)
    {
        cin>>grid[i];
    }

    int dp[h][w][2];
    memset(dp, 0, sizeof(dp));

    for(int j = 0; j < w; j++)
    {
        if(grid[h-1][j] == 'X')
            dp[h-1][j][0] = 1;
    }

    for(int i = h-1; i >= 0; i--)
    {

        vector<int>pref(w+1, 0);
        for(int j = 0; j < w; j++)
        {
            pref[j+1] = pref[j] + dp[i][j][0]*(grid[i][j] == 'X');
        }

        for(int j = 0 ; j < w; j++)
        {
            if(grid[i][j] == '#')continue;
            int lef = max(0LL, j-d);
            int rig = min(w-1, j+d);

            dp[i][j][1] = pref[rig+1] - pref[lef] - dp[i][j][0];          
        }
        
        if(i == 0) continue;

        pref.assign(w+1, 0);
        for(int j = 0; j < w; j++)
        {
            pref[j+1] = pref[j] + (dp[i][j][0]+dp[i][j][1])*(grid[i][j] == 'X');
        }

        
        for(int j = 0 ; j < w; j++)
        {
            if(grid[i-1][j] == '#')continue;

            int lef = max(0LL, j-(ll)sqrtl(d*d - 1));
            int rig = min(w-1, j+(ll)sqrtl(d*d - 1));
            
            dp[i-1][j][0] = (pref[rig+1] - pref[lef])%MOD;
        }
    }

    int ans = 0;
    for(int j = 0; j< w; j++)
    {
        ans += dp[0][j][0] + dp[0][j][1];
        ans%=MOD;
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