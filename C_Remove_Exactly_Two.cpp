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
    vector<set<int>>adj(n+1);
    vector<int>deg(n+1, 0);

    for(int i =0; i<n-1; i++)
    {
        int u, v; cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);

        deg[u]++;
        deg[v]++;
    }

    // for(auto it:deg)
    // {
    //     cout<<it<<space;
    // }cout<<nl;

    vector<pair<int, int>>tt;

    for(int i = 1; i<= n; i++)
    {
        tt.push_back({deg[i], i});
    }

    sort(all(tt));
    reverse(all(tt));
    
    int ans = 0;

    for(int i = 0; i< tt.size(); i++)
    {
        int tempans = tt[i].first;
        int ind = tt[i].second;
        for(int j = i+1; j< tt.size(); j++)
        {
            int deg2 = tt[j].first;
            int ind2 = tt[j].second;
            if(adj[ind].find(ind2) == adj[ind].end())
            {
                ans = max(ans, tempans + deg2 -1);
                break;
            }
            else
            {
                ans = max(ans, tempans + deg2 - 2);
            }
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