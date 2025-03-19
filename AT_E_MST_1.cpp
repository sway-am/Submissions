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
/*
    Just add all he query edges to the the adj matix, but we can mark them as different
    then apply prims algorithm.

    when we travese a edge that is marked we can know that query affects the MST
    so we can store that in the answer.

    Note that when we are at a node that is reached by traversing a marked edge
    we should not mark that node as visited.

    O((q + m) log(q+m))

    simple implementation
*/

void solve()
{
    ll n, m, q; cin>>n>>m>>q;
    vector<vector<vector<int>>>adj(n);
    for(int i = 0; i < m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        u--; v--;
        adj[u].push_back({v, w, -1});
        adj[v].push_back({u, w, -1});
    }

    vector<int>ans(q, 0);

    for(int i =0 ; i< q; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        u--; v--;
        adj[u].push_back({v, w, i});
        adj[v].push_back({u, w, i});
    }

    vector<int>vis(n, 0);

    

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
    pq.push({0, 0, -1});
    
    while(!pq.empty())
    {
        int wt = pq.top()[0];
        int node = pq.top()[1];
        int quer = pq.top()[2];
        pq.pop();

        if(vis[node])
        {
            continue;
        }

        if(quer != -1)
        {
            ans[quer] = 1;
            continue;
        }

        vis[node] = 1;

        for(auto it:adj[node])
        {
            int nex = it[0];
            if(!vis[nex])
            {
                pq.push({it[1], it[0], it[2]});
            }
        }
    }

    for(auto it:ans)
    {
        if(it)
        {
            cout<<"Yes"<<nl;
        }
        else
        {
            cout<<"No"<<nl;
        }
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