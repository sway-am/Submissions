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
bool check(ll n) {
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for (ll i = 3; i * i <= n; i += 2) {
        if(n % i == 0)
            return false;
    }
    return true;
}

void solve()
{
    ll x;
        int k;
        cin >> x >> k;

        if(k == 1) 
        {
           if(check(x)) {cout<<"YES"<<nl;return;}
           else
           {
            cout<<"NO"<<nl;
            return;
           }
        }
        
     
        if(x != 1){
            cout << "NO" << nl;
            return;
        }

        if(k == 2)
            cout << "YES" << nl;
        else
            cout << "NO" << nl;
}



signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t =1;
  cin>>t;
  while(t--){
    solve();


  }
  return 0;
}