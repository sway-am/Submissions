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


void solve()
{
    int n; cin>>n;
    vector<int>v(n);vin(v, n);
    set<int>st(all(v));

    for(auto it:v)
    {
        int x = it+1;
        if(st.find(x) != st.end() || st.find(x-2) != st.end())
        {
            cout<<2<<nl;return;
        }

    }

    cout<<1<<nl;


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