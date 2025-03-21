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

bool cycleFound = false;
vector<int> parent;
vector<int> visited;
vector<vector<int>> adj;
set<int> cycleNodes;
int cycleStart = -1, cycleEnd = -1;
/*
   For N vertices there are N-1 edges and thus there is exactly one
   cycle, we need to find that cycle

   After finding the cycle note that in the query if both the queries lie 
   on the cycle then answer is no.

   the two nodes of the query must lie on the same branch. Cuz if they 
   lie in separate branches we can have multiple paths using the cycle

   To do this we can consider each element of the cycle as a starting node
   and then do dsu on their respective branches.

   if both the nodes belong to the same branch ie. the same component then path is
   unique.
*/
struct DSU {
    vector<int> parent, size, rank;
    bool useSize = true;
    DSU(int n, bool useSize = true) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);
        this->useSize = useSize;
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        return parent[x] = (parent[x] == x) ? x : find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;

        if (useSize) {
            if (size[x] < size[y]) {
                parent[x] = y;
                size[y] += size[x];
            } else {
                parent[y] = x;
                size[x] += size[y];
            }
        } else {
            if (rank[x] < rank[y]) {
                parent[x] = y;
            } else if (rank[x] > rank[y]) {
                parent[y] = x;
            } else {
                parent[y] = x;
                rank[x]++;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
void dfs(int node, int par) {
  visited[node] = 1;
  parent[node] = par;
  for (int nxt : adj[node]) 
  {
      if (nxt == par) continue; 
      if (visited[nxt]) 
      {
          
          cycleFound = true;
          cycleStart = nxt;
          cycleEnd = node;
          return;
      }
      dfs(nxt, node);
      if (cycleFound) return; 
  }
}

void findCycle(int n) 
{
  parent.assign(n, -1);
  visited.assign(n, 0);
  cycleStart = -1; cycleEnd = -1;
 
  for (int i = 0; i < n; i++) 
  {
      if (!visited[i]) {
          dfs(i, -1);
          if (cycleFound) break;
      }
  }
   
   if (cycleFound) 
   {
    int cur = cycleEnd;
    cycleNodes.insert(cycleStart);
    while (cur != cycleStart) 
    {
        cycleNodes.insert(cur);
        cur = parent[cur];
    }
  }
}

void dfs1(int node, int par, DSU& dsu)
{
  visited[node] = true;
  for(auto it:adj[node])
  {
    if(cycleNodes.find(it) != cycleNodes.end() || it == par) continue;
    if(!dsu.connected(it, node))
    {
      dsu.unite(it, node);
    }

    dfs1(it, node, dsu);
  }
}



void solve()
{
    ll n; cin>>n;
    adj.resize(n);
    for(int i = 0; i < n; i++)
    {
        ll u, v; cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    findCycle(n);

    DSU dsu(n);

    visited.resize(n, 0);
    for(auto it:cycleNodes)
    {
      dfs1(it, -1, dsu);
    }

    // for(auto it:cycleNodes)
    // {
    //   cout<<it<<space;
    // }cout<<nl;

    int q; cin>>q;
    while(q--)
    {
      ll u , v; cin>>u>>v;
      u--; v--;

      if(cycleNodes.find(u) == cycleNodes.end() || cycleNodes.find(v) == cycleNodes.end())
      {
        if(dsu.connected(u, v))
        {
          cout<<"Yes"<<nl;
        }
        else
        {
          cout<<"No"<<nl;
        }
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
  ll t =1 ;
//   cin>>t;
  while(t--){
    solve();


  }
  return 0;
}