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
     Make 3n states, and make the distance vector with respect to modulo 3
     just a normal dijsktra modification
*/


void solve()
{
    ll n, m; cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i =0 ; i< m; i++)
    {
        ll u, v; cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
    }
    ll st, en; cin>>st>>en;
    st--; en--;

    vector<vector<int>>dis(n, vector<int>(3, INT_MAX));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    q.push({0, st});
    dis[st][0] = 0;

    while(!q.empty())
    {
        int d = q.top()[0];
        int node = q.top()[1];
        // int cnt = q.top()[3];
        q.pop();
        if(node == en && d%3 == 0)
        {
            cout<<d/3<<nl;
            return;
        }

        for(auto it:adj[node])
        {
            if(dis[it][(d+1)%3] > d+1)
            {
                dis[it][(d+1)%3] = d+1;
                q.push({d+1, it});
            }
        }
    }

    cout<<-1<<nl;
    return;



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