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
    ll n ; cin>>n;
    vector<int>v;
    for(int i = 0; i < n-2; i++)
    {
        ll temp;
        cin>>temp;
        v.push_back(temp);
    }

    if(v.size() < 3)
    {
        cout<<"YES"<<nl;return ;
    }


    for(int i = 0; i<v.size()-2; i++)
    {
        if(v[i] == 1 && v[i+1] == 0 && v[i+2] == 1)
        {
            cout<<"NO"<<nl;return;
        }
    }

    cout<<"YES"<<nl;


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