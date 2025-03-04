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

ll k;
ll cal() {
    ll a = 1, b = -1, c = -(2*k);
    ll x1 = sqrtl(((b*b) - (4*a*c))*1.0);
    x1 = (-b + x1)/(2*a);
    ll tot = (x1 * (x1 - 1))/2;
    k -= tot;  
    return x1;
}
void solve() {
    cin >> k;
    vector<pair<ll,ll>>ans(500);
    for(ll i = 0; i < 500; i++) {
        ans[i] = {i,i};
    }  
    ll cur = 0;
    while(k) {
        ll x = cal();
        ll y = x;  
        x--;
        ll i = cur+1;
        while(x) {
            ans[i].first = ans[cur].first;
            i++;
            x--;
        }
        cur += y;
    }
    cout << 500 << endl;
    for(ll i = 0; i < 500; i++) {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
 
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