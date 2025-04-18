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

    map<int, int>mp;    
    int ans = INT_MAX;
    for(int  i=0; i<n; i++)
    {
        if(mp.find(v[i])==mp.end())
        {
            mp[v[i]] = i; continue;
        }
        
        ans = min(ans, i - mp[v[i]]+1);
        mp[v[i]] = i;
    }

    if(ans != INT_MAX) cout<<ans<<nl;
    else cout<<-1<<nl;

}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t =1 ;
//   cin>>t;
  while(t--){
    solve();


  }
  return 0;
}