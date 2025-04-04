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
const int MOD = 998244353;
#define INF (ll)1e+15
 
using namespace std;
typedef int ll;


void solve()
{
    ll n, k, x; cin>>n>>k>>x;
    vector<int>v(n); vin(v, n);

    ll S= 0;
    for(auto it:v) S+= it;

    vector<int>pref(n);
    pref[0] = v[0];
    for(int i = 1; i< n; i++) pref[i] = pref[i-1] + v[i];
    

    ll ans =0 ;
    for(int i =0 ; i< n; i++)
    {
        ll rem = S;
        if(i != 0) rem -= pref[i-1];

        if(rem >= x) ans += k;
        else
        {
            ll req = x - rem;
            ll ext = ceill(req /(double)S);

            if(ext <k) ans += (k-ext);

        }

    }
    cout<<ans<<nl;

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