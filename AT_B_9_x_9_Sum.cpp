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
    int ans = 0;
    map<int ,int> mp;
    for(int i = 1; i<= 9 ; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            mp[i*j] ++;
            ans += i*j;
        }
    }

    ans -= mp[n]*n;
    cout<<ans<<nl;

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