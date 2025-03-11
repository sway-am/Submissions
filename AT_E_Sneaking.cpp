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
const int INF = 1e18;
/*
    Normal Mode (mode 0):
    You can move right, left, and down with the given costs. Also, you can switch to climbing mode at the current cell with an extra cost of 1.

    Climbing Mode (mode 1):
    You are only allowed to switch back to normal mode (at no extra cost) and move upward (which costs 1).


    we the use dijsktra and switch between these 2 modes.
*/
void solve()
{
    ll n, m; cin>>n>>m;
    vector<vector<pair<int, int>>> grid;
    grid.resize(n + 1, vector<pair<int, int>>(m + 1, {0, 0}));
    for(int i = 1; i<= n;i++)
    {
        for(int j = 1; j <= m-1; j++)
        {
            ll temp; cin>>temp;
            grid[i][j].F = temp;
        }
    }

    for(int i = 1; i<= n-1; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            ll temp; cin>>temp;
            grid[i][j].S = temp;
        }
    }

    vector<vector<int>> vis(n+1, vector<int>(m+1, INF));
    vector<vector<int>>alt(n+1, vector<int>(m+1, INF));

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 1, 1, 0});
    
    while(!pq.empty())
    {
        int cst = pq.top()[0];
        int x = pq.top()[1];
        int y = pq.top()[2];
        bool par = pq.top()[3];
         

        if(x == n && y == m)
        {
            cout<<cst<<nl;
            return;
        }
        pq.pop();

         
        if(!par)
        {
            if (cst >= vis[x][y]) continue;
            vis[x][y] = cst;

            if(x + 1 <= n && vis[x +1][y] > cst + grid[x][y].S)
            {
                pq.push({cst + grid[x][y].S, x+1, y, 0});
            }
            if(y + 1 <= m && vis[x][y+1] > cst + grid[x][y].F)
            {
                pq.push({cst + grid[x][y].F, x, y+1, 0});
            }
            if( y - 1 >= 1 && vis[x][y-1] > cst + grid[x][y-1].F)
            {
                pq.push({cst+grid[x][y-1].F, x, y-1, 0});
            }
            if(alt[x][y] > cst +1)
            {
                pq.push({cst +1, x, y, 1});
            }
        }
        else
        {
            if (cst >= alt[x][y]) continue; 
            alt[x][y] = cst;
            if(x - 1 >= 1 && alt[x-1][y] > cst + 1)
            {
                pq.push({cst + 1, x-1, y, 1});
            }
            if(vis[x][y] > cst)
            {
                pq.push({cst, x, y, 0});
            }
        }
    }


    cout<<vis[n][m]<<nl;

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