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
    Treat the set no as special indexes to count the number of set change
    ie. set changes are same as merging two sets
  */

  void solve()
  {
    ll n, m; cin>>n>>m;
    vector<vector<int>>adj(n+m+100);
    
    for(int i =1 ; i<= n;i++)
    {
      int l ; cin>>l;

      int spec = m + i;
      for(int j = 0; j < l; j++)
      {
        ll x; cin>>x;
        adj[x].push_back(spec);
        adj[spec].push_back(x);
      }
    }

    int ans = 1e9;
    vector<int>vis(n+m+100, 0);

    queue<vector<int>>q;
    q.push({1, 0, -1});

    while(!q.empty())
    {
      int node = q.front()[0];
      int stps = q.front()[1];
      int par = q.front()[2];
      q.pop();

      if(node == m)
      {
        ans = min(ans , stps);
      }

      if(vis[node]) continue;

      vis[node] = 1;

    
      for(auto it:adj[node])
      {
        

        if(it > m) q.push({it, stps +1, node});
        else q.push({it, stps, node});
      }
    }

    if(ans == 1e9) {cout<<-1<<nl;return;}
    cout<<ans-1<<nl;



  }

  signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t =1;
    // cin>>t;
    while(t--){
      solve();


    }
    return 0;
  }