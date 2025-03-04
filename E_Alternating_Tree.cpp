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


/*

        HAD TO SEE SOLUTION
*/
using namespace std;
typedef int ll;

const int M=1000005,mod=1e9+7;
vector<int> adj[M];
int par[M],lev[M];
ll v[M];
ll e[M],o[M];
ll ans,res,n;

void dfs(int x, int depth)
{
    lev[x] = depth;
    int cno = 0;
    
    for (int i = 0; i < adj[x].size(); i++)
    {
        int c = adj[x][i];
        if (c != par[x])
        {
            par[c] = x;
            dfs(c, depth + 1);
            
            if (cno > 0)
            {
                ans = ( (ans + 2 * ( o[x] * e[c] % mod - e[x] * o[c] % mod + mod ) % mod * v[x] % mod) + mod ) % mod;
            }
            
            cno++;
            o[x] += e[c];
            e[x] += o[c];
        }
    }
    o[x]++;  
}


void solve()
{
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);
    
    for (int i = 1; i <= n; i++)
    {    
        if (lev[i] % 2)
        {
            ans = ((ans + 2 * ( o[i] * (e[1] - o[i] + 1) % mod - e[i] * (o[1] - e[i]) % mod + mod ) % mod * v[i] % mod) + mod) % mod;
        }
        else
        {
            ans = ((ans + 2 * ( o[i] * (o[1] - o[i] + 1) % mod - e[i] * (e[1] - e[i]) % mod + mod ) % mod * v[i] % mod) + mod) % mod;
        }
        
        ans = ((ans - v[i]) % mod + mod) % mod;
    }
    
    cout << ans << endl;

}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t =1 ;
//   cin>>t;
  while(t--){
    solve();


  }
  return 0;
}