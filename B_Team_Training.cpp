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
    int n, x;
    cin>>n;cin>>x;
    vector<int>v(n);
    vin(v, n);
    sort(all(v));
    reverse(all(v));

    int cntr = 0;
    int ans =0;
    for(int i =0 ; i< n; i++)
    {
        cntr++;
        if(v[i] * cntr >= x)
        {
            ans++;
            cntr = 0;
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