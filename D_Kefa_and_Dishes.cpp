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
/*
    This is a bit mask dp quesion, here the trick in the question that we have to see
    the last selected dish, as there are bonuses. so cwe need last selected dish and then we can
    brute force the next dist as n is atmost 18

    now an efficient way to solve this problem is to use bitmasks
    the mask can represent the dishes that are currently selected
    dp[mask][last] -> mask of dishes that are already selected and last represents the last dist that
    is selected

    this is a brute force question with a sprinkle of bitmask dp

    reading the hackerrank bitmask dp helped in solving this question
    
*/

 
using namespace std;
typedef int ll;


void solve()
{
    ll n, m, k;
    cin>>n>>m>>k;
    vector<int>a(n);vin(a, n);
    map<int, map<int,int>>mp;

    for(int i =0 ; i< k; i++)
    {
        ll x, y, c; cin>>x>>y>>c;
        // int last = (1<<(x-1));
        mp[x-1][y-1] = c;
    }

    vector<vector<int>>dp((1<<n), vector<int>(n+1,-1));
    //dp[mask][last]

    for(int i = 0; i< n; i++)
    {
        dp[(1<<i)][i] = a[i];
    }

    for(int i = 0; i < (1<<n); i++) // mask
    {
        for(int j = 0; j < n; j++) //last
        {
            if(dp[i][j] < 0) continue;

           for(int k = 0; k < n; k++) //next
           {
                if(i&(1<<k)) continue;

                int newdp = dp[i][j] + a[k] + mp[j][k];
                dp[(i | (1 << k))][k] = max(dp[(i | (1 << k))][k], newdp);
           }
        }
    }
    
    int ans = 0;
    for(int i =0 ; i< (1<<n); i++)
    {
        if(__builtin_popcount(i) != m) continue;

        for(int j = 0; j< n; j++)
        {
            ans =max(ans, dp[i][j]);
        }
    }
    cout<<ans<<nl;



}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t =1;
//   cin>>t;
  while(t--){
    solve();


  }
  return 0;
}