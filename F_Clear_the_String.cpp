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
    Select the the subproblem ou want to solve.
    Use recurssion to solve it and use dp.
*/

vector<vector<int>>dp;
int dfs(int l, int r, string& s)
{

  if(l == r)
  {
    return 1;
  }

  if(l > r)
  {
    return 0;
  }

  int ans = 1 + dfs(l +1, r, s);

  if(dp[l][r] != -1)
    return dp[l][r];

  for(int i = l+1; i <= r; i++)
  {
    if(s[l] == s[i])
    {
      ans = min(ans, dfs(l+1, i-1, s) + dfs(i, r, s));
    }
  }

  return dp[l][r] = ans;



}

void solve()
{
  ll n; cin>>n;
  string s; cin>>s;
  dp.assign(n+1, vector<int>(n+1, -1));

  cout << dfs(0, n-1, s)<<nl;

}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
//   cin>>t;
  while(t--){
    solve();


  }
  return 0;
}