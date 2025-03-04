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
bool dfs(vector<int>& v, int ind, int modl, int& m, vector<vector<int>>& dp)
{
    if(ind < 0) 
    {
        return 0;
    }

    if(dp[ind][modl] != -1)
    {
        return dp[ind][modl];
    }

    if((modl + v[ind])% m == 0)
    {
        return dp[ind][modl] = 1;
    }
    else
    {
        return dp[ind][modl] = dfs(v, ind-1, modl, m, dp) || dfs(v , ind-1, (modl + v[ind])% m, m,dp);
    }
}


void solve()
{
    ll n; cin>>n; 
    ll m; cin>>m;
    vector<int>v(n);

    

    vin(v, n);
    /*
        Pigeon Hole principle used. If N>= M there alaways exists a solution for divisiblility.
        Think by yourself.
    */
    if(n >= m) 
    {
        cout<<"YES"<<nl;
        return ;
    }


    for(int i =0 ; i< n; i++)
    {
        v[i] = v[i]%m;

        if(v[i] == 0)
        {
            cout<<"YES"<<nl;
            return;
        }
    }

    vector<vector<int>>dp(n+5, vector<int>(m+ 5, -1));


    if(dfs(v, n-1, 0, m, dp))
        cout<<"YES"<<nl;

    else
        cout<<"NO"<<nl;

    return;

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