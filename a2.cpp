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
    ll n, m ; cin>>n>>m;
    vector<vector<pair<int, int>>>adj(n+1);
    for(int i =0 ; i< m; i++)
    {
        ll u, v, w; 
        
        cin>>u>>v>>w;
        u--;v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int>slw(n);
    vin(slw, n);
    int goal = n-1;

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    pq.push({0, 0, slw[0]});
    vector<int>vis(n, 0);

    while(!pq.empty())
    {
        int tim = pq.top()[0]; int node = pq.top()[1]; int cycl = pq.top()[2];
        pq.pop();

        if(node == goal)
        {
            cout<<tim<<nl;
            return;
        }
        vis[node] = 1;

        for(auto it:adj[node])
        {
            int nex = it.first; int w = it.second;
            if(vis[nex])
            {
                continue;
            }

            int newtim = tim + w*cycl;
            pq.push({newtim, nex, min(cycl, slw[nex])});
            // pq.push({newtim, nex, slw[nex]});
        }


    }

    cout<<-1<<nl;

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
