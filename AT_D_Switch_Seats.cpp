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
    vector<int>v(2*n); vin(v, 2*n);
    map<int, vector<int>>mp;
    for(int i = 0; i< 2*n; i++)
    { 
        int it = v[i];
        mp[it].push_back(i);
    }

    set<pair<int, int>>st;

    for(int i = 0; i< 2*n-1; i++)
    {
        int a = v[i];
        int b = v[i+1];
        if(a == b)continue;

        if(mp[a][0]+1 == mp[a][1]) continue;
        if(mp[b][0]+1 == mp[b][1]) continue;

        vector<int>temp = {mp[a][0], mp[a][1], mp[b][0], mp[b][1]};
        sort(all(temp));

        if(temp[0] + 1 == temp[1] && temp[2] + 1 == temp[3])
        {
            if(a > b) swap(a, b);
            st.insert({a, b});
        }
    }

    cout<<st.size()<<nl;



}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  cin>>t;
  while(t--){
    solve();


  }
  return 0;
}