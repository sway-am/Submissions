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

    ll n, k; cin>>n>>k;
    vector<int>v(n+1, 0);
    v[n] = n-1;
    v[n-1] = n;


    for(int i = 1; i<= n-2; i++)
    {
        if(k%2 == 0)
            v[i] = n-1;
        else
            v[i] = n;
    }

    for(int i = 1; i<= n; i++)
    {
        cout<<v[i]<<space;
    }cout<<nl;
        
    

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