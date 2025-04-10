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
const int MOD = 998244353;
#define INF (ll)1e+15
 
using namespace std;
typedef int ll;
/*
    we dont need to iterate over all the point, just iterater over the segments in
    a sorted order.
    
    and keep removing outdated segments. Whenever number of segments is greater than
    k we can remove the one with the futhest reach.
    this ensures maximum efficiency.

    Previous mistake made was removing the segment with the biggest range but that 
    is not correct as the range might be big but it might lie left of the point of
    interest
*/


void solve()
{
    ll n, k; cin>>n>>k;

    vector<tuple<int, int, int>>seg;
    for(int i = 0; i< n; i++)
    {
        ll x, y; cin>>x>>y;
        seg.push_back({x, y, i});
    }

    sort(all(seg));

    multiset<tuple<int, int>>st;
    vector<int>ans;
    for(auto&[l , r, ind]:seg)
    {
        st.insert({r, ind});

        while (!st.empty() && get<0>(*st.begin()) < l) 
        {
            st.erase(st.begin());
        }

        while(st.size() > k )
        {
            auto&[r1, ind1] = *st.rbegin();
            ans.push_back(ind1);
            st.erase({r1, ind1});
        }
    }

    cout<<ans.size()<<nl;
    sort(all(ans));
    for(auto it:ans)
    {
        cout<<it+1<<space;
    }cout<<nl;


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