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
    HINT WAS TAKEN

    So basically this problem can be solved if we travell in reverse order.
    assume we already have reached the final stating at a very great time, say 2e18 now we check in reverse
    the curr time should be > l + c obviously else we cant ever depart from a.

    currtime >=  l + c + (x-1)*d
    so we get x <= (currtime - l -c)/d + 1
    also x <= k therefore x is 
    x = min(k , (currtime - l -c)/d + 1))

    Now that we have x we can calculate the departure time as

    l + d(x-1)

    put that in the dp. the dp store the departure time from all the stations.
    


*/


void solve()
{
    ll n, m; cin>>n>>m;
    vector<vector<vector<int>>>adj(n);
    for(int i = 0; i< m ;i++)
    {
        int l, d, k, c, A, B;
        cin >> l >> d >> k >> c >> A >> B;
        A--; B--;
        adj[B].push_back({A, l , d, k, c});
    }

    vector<int>dp(n, 0);
    dp[n-1] = 2e18;

    priority_queue<pair<int, int>>pq;

    pq.push({dp[n-1], n-1});

    while(!pq.empty())
    {
        ll currtime = pq.top().F;
        ll ind = pq.top().S;
        pq.pop();

        
        for(auto it:adj[ind])
        {
            int u = it[0]; int l = it[1]; int d = it[2]; int k = it[3]; int c = it[4];
            
            /*
                currtime >= l + d*(x-1) + c
                x = (currtime - l - c)/d + 1
            */ 


            if(currtime >= l+c)
            {
                int xlim = (currtime - l - c)/d + 1;
                xlim = min(xlim, k);

                ll time = l + d*(xlim -1) ;
                if(time >= dp[u])
                {
                    dp[u] = time;
                    pq.push({dp[u] , u});
                }
            }

        }
    }

    for(int i =0; i < n-1; i++)
    {
        if(!dp[i])
        {
            cout<<"Unreachable"<<nl;
        }
        else
        {
            cout<<dp[i]<<nl;
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