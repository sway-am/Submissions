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
#define INF (ll)1e+15

/*
    we can just do brute force as at max the path length is 5.
    so we can 5! combination and 2^5 number of ways of configuring direction
    so total complexity of answering each query can be written as
    5! * 2^5 which ~ 4*1e4

    so we just use floyd warshall to compute the distance between each node
    and then we check for each coniguration of path and direction and give
    the best possible answer.
*/



vector<int>u, v, t;
vector<vector<int>>d;
vector<int>path;
int totalIslands;
int dfs(int ind, int n) {
    if (ind == n) {
        int best = INF;
   
        for (int mask = 0; mask < (1 << n); mask++) {
            int cost = 0;
            int curr = 0; // starting island (0)
            for (int i = 0; i < n; i++) {
                int bridgeIndex = path[i];
                if (mask & (1 << i)) {
                    
                    cost += d[curr][u[bridgeIndex]] + t[bridgeIndex];
                    curr = v[bridgeIndex];
                } else {
                    
                    cost += d[curr][v[bridgeIndex]] + t[bridgeIndex];
                    curr = u[bridgeIndex];
                }
            }
            cost += d[curr][totalIslands - 1];  
            best = min(best, cost);
        }
        return best;
    }
    
    int ans = INF;
    for (int i = ind; i < n; i++) {
        swap(path[i], path[ind]);
        ans = min(ans, dfs(ind + 1, n));
        swap(path[i], path[ind]); // backtrack
    }
    return ans;
}

void solve()
{
    ll n, m; cin>>n>>m;
    totalIslands = n;
    d.resize(n, vector<int>(n , INF));
    u.resize(m); v.resize(m); t.resize(m);

    for(int i = 0; i< m; i++)
    {
        cin>>u[i]>>v[i]>>t[i];
        u[i]--; v[i]--;
        d[u[i]][v[i]] = min(t[i],d[u[i]][v[i]]);
        d[v[i]][u[i]] = min(t[i],d[v[i]][u[i]]);
    }

    

    for(int i = 0; i< n; i++) d[i][i] = 0;

    for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);


    ll q; cin>>q;
    while(q--)
    {
        path.clear();
        ll l; cin>>l;
        for(int i = 0; i< l ;i++)
        {
            ll x; cin>>x;
            path.push_back(x-1);
        }

        cout<<dfs(0, l)<<nl;
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