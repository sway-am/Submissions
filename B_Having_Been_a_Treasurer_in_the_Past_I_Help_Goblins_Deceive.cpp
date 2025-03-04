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
    string s; cin>>s;

    int top =0 ;
    int bot = 0;
    for(auto it:s)
    {
        if(it == '-')
        {
            top ++;
        }
        else
        {
            bot++;
        }
    }

    if(top < 2 || bot < 1)
    {
        cout<<0<<nl;
        return;
    }

    int x1 = top /2;
    int x2 = (top + 1)/2;
    cout<<x1*x2*bot<<nl;




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