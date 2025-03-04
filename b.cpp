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

  double log_r = log((double)v[1]) - log((double)v[0]);
    
    for (int i = 1; i < n - 1; i++) {
        double chk = log((double)v[i + 1]) - log((double)v[i]);
        if (abs(log_r - chk) > 1e-15) {
            cout << "No" << nl;
            return;
        }
    }
    cout << "Yes" << nl;


}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  // cin>>t;
  while(t--){
    solve();


  }
  return 0;
}