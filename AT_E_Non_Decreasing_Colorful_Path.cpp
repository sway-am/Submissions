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
    We need a minheap wrt to the val of the node as at every turn
    we are motivated to have the smallest val so that the chance 
    of getting 0 is less, and the
    -score because we also want the largest unq numbers but as we made it a 
    minheap we have to do -score.
*/


void solve()
{
    ll n, m; cin>>n>>m;
    vector<int> val(n+1, 0);
    for(int i = 0; i<n; i++) {int temp; cin>>temp; val[i+1] = temp;}

    vector<vector<int>>adj(n+1);
    for(int i = 0 ; i < m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
    pq.push({val[1], -1, 1});

    vector<int>pro(n+1, 0);
    pro[1] = 1;

    while(!pq.empty())
    {
        int curVal = pq.top()[0];
        int score = -pq.top()[1];
        int node = pq.top()[2];
        pq.pop();

        if(score < pro[node]) continue;

        for(auto u:adj[node])
        {
            if(val[u] < val[node]) continue;

            int newscore = score + (val[u] > val[node]);

            if(pro[u] < newscore)
            {
                pro[u] = newscore;
                pq.push({val[u], -newscore, u});
            }
        }
    }

    cout<<pro[n]<<nl;


    

}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
//   cin>>t;
  while(t--){
    solve();


  }
  return 0;
}