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


void solve()
{
    ll n; cin>>n;
    vector<int>v(n);
    vin(v, n);

    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

    for(int i = 0; i<n; i++)
    {
        int del = 0; 
        for(int j = i; j < n; j++)
        {
            if(v[i] > v[j])
            {
                del--;
            }
            else if(v[i] < v[j])
            {
                del++;
            }

            dp[i][j] = del;
        }
    }

    int ans = 0;
    int l = 0; int r = 0;

    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(dp[i][j] < ans)
            {
                ans = dp[i][j];
                l = i;
                r = j;
            }
        }
    }

    cout<<l+1<<space<<r+1<<nl;


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