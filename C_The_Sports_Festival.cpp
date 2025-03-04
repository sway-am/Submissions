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
    Sort the array
    say now array is 
    a1 a2 a3 ..... an

    Now either a1 or an will be the last element to minimize the cost as it is the longest segment
    Now if we fix an, check from a1 to an-1
    if we fix a1 check from a2 to an

    repeat this process untill i == j

    This code can be written recursively very easily
*/


void solve()
{
    ll n; cin>>n; vector<int>a(n);
    vin(a, n);
    sort(all(a));
    vector<vector<int>>dp(n+5, vector<int>(n+5, 0));
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;

    
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l <= n - len; l++) {
            int r = l + len - 1;
            dp[l][r] = a[r] - a[l] + min(dp[l + 1][r], dp[l][r - 1]);
        }
    }

    cout << dp[0][n - 1] << '\n';


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