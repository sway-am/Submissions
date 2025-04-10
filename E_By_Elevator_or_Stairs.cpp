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
    ll n, c; cin>>n>>c;
    vector<int>a(n-1), b(n-1);
    vin(a, n-1);vin(b, n-1);

    vector<vector<int>>dis(2, vector<int>(n, INF));

    dis[0][0] = 0;
    // dis[1][0] = 0;

    //dis, node, mode

    priority_queue<tuple<int, int, int>, 
        vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;

    pq.push({0, 0, 0});

    while(!pq.empty())
    {
        auto[d, node, mode] = pq.top();
        pq.pop();
        
        if(dis[mode][node] < d || node == n-1) continue;

        if(mode == 0)
        {
            // cout<<mode<<nl;
            if(dis[1][node] > c + d)
            {
                dis[1][node] = c +d;
                pq.push({c+d, node,1});
            }

            if(dis[mode][node+1] > d + a[node])
            {
                // cout<<node<<space<<mode<<nl;
                dis[mode][node+1] = d + a[node];
                pq.push({dis[mode][node+1], node+1, 0});
            }
        }
        else
        {
            if(dis[0][node] > d)
            {
                dis[0][node] = d;
                pq.push({d, node, 0});
            }

            if(dis[mode][node+1] > d + b[node])
            {
                dis[mode][node+1] = d + b[node];
                pq.push({dis[mode][node+1], node+1, 1});
            }
        }
    }

    // for(int i = 0; i< n; i++)
    // {
    //     cout<<dis[0][i]<<space;
    // }
    // cout<<nl;
    // for(int i = 0; i< n; i++)
    // {
    //     cout<<dis[1][i]<<space;
    // }

    for(int i =0 ; i< n; i++)
    {
        cout<<min(dis[0][i], dis[1][i])<<space;
    }cout<<nl;




}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t =1;
//   cin>>t;
  while(t--){
    solve();


  }
  return 0;
}