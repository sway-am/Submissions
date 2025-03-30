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
    vector<int>v(n); vin(v, n);
    map<int, int>mp;
    for(auto it:v){mp[it]++;}
    

    vector<pair<int, int>>cnts;
    for(auto it:mp)
    {
        cnts.push_back({it.F, it.S});
    }
    sort(all(cnts));
    reverse(all(cnts));
    int k = 1 ;

    for( auto it:cnts)
    {
        int no = it.F;
        int f = it.S;

        mp[no] = k;
        k += f;
    }

    for(auto it:v)
    {
        cout<<mp[it]<<endl;
    }
    


    


}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
//   cin>>t;
  while(t--){
    solve();


  }
  return 0;
}