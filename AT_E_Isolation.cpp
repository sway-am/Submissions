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
    Can be done direcly, just maintain a set for the vertices which are
    currently alone so that can be ansered in o(1) time.
    And then make the adj matix of set so you can perform addition and deletion of edges


    Each edge is inserted once and removed once, so the total number of edge insertions and deletions across q queries is at most O(n + q).
    Since each insertion or deletion in set is O(log n), the total cost of all operations is:
    𝑂((𝑛+𝑞)log⁡𝑛)
    Thus, the worst-case time complexity of the entire program is:
    O((n+q)logn)
*/


void solve()
{
    ll n, q; cin>>n>>q;
    vector<set<int>>adj(n+1);
    set<int>st;

    for(int i = 1; i<= n; i ++)
    {
        
        st.insert(i);
    }

    while(q--)
    {
        ll op;
        cin>>op;
        if(op == 1)
        {
            ll u, v; cin>>u>>v;
            if(st.find(u) != st.end())
            {
                st.erase(u);
            }

            if(st.find(v) != st.end())
            {
                st.erase(v);
            }

            adj[u].insert(v);
            adj[v].insert(u);

            cout<<st.size()<<nl;
        }
        else
        {
            ll u; cin>>u;
            st.insert(u);
            for(auto it:adj[u])
            {
                adj[it].erase(u);
                if(adj[it].size()==0)
                {
                    st.insert(it);
                }
            }

            adj[u].clear();
            cout<<st.size()<<nl;
        }
    }




}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t= 1;
//   cin>>t;
  while(t--){
    solve();


  }
  return 0;
}