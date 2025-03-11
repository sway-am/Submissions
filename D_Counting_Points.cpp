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
    ll n, m; cin>>n>>m;
    vector<int>xcod(n); vin(xcod,n);
    vector<int>rad(n); vin(rad,n);

    vector<pair<int, int>>circ;
    for(int i =0 ; i< n; i++)
    {
        circ.push_back({xcod[i], rad[i]});
    }

    sort(all(circ));

    map<int, pair<int, int>>fin;

    for(int i = 0; i< n; i++)
    {
        int x = circ[i].F;
        int r = circ[i].S;
        // cout<<x<<space<<r<<nl;

        for(int i = x - r; i <= x +r; i++)
        {
            int ylim = floorl(sqrt(r*r - (i - x)*(i-x)));

            fin[i].F = max(fin[i].F, ylim);
            fin[i].S = max(fin[i].S, ylim);
        }
    }

    int ans =  0 ;

    for(auto it:fin)
    {

        int ytop = it.second.F;
        int ybot = it.second.S;

        // cout<<it.F<<space<<ytop<<nl;

        if(ytop == 0)
        {
            ans += 1;
        }
        else
        {
            ans += (2*ytop + 1);
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