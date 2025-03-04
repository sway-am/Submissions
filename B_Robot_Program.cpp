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
    ll n, x, k;
    cin>>n>>x>>k;
    string s; cin>>s;

    vector<int>v;
    // v.push_back(0);

    for(auto it:s)
    {
        if(it == 'L')
        {
            v.push_back(-1);
        }
        else
        {
            v.push_back(+1);
        }
    }

    vector<int>pref;
    pref.push_back(v[0]);
    for(int i = 1; i< n; i++)
    {
        pref.push_back(pref[i-1] + v[i]);
    }

    int miniloop = 0;
    ll su = 0;
    for(int i = 0; i< n; i++)
    {
        if(pref[i] == 0)
        {
            miniloop = i+1;
            break;
        }
    }

    int cntr = 0; 
    
    for(int i = 1; i <= min(n, k); i++)
    {
        int iter = i-1;
        x += v[iter];
        if(x == 0)
        {
            cntr++;
            if(miniloop != 0)
                cntr += (k-i)/miniloop;
            break;
        }
    }

    cout<<cntr<<nl;


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