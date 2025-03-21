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
    1. Observation:
    For any interval S = {L, L+1, ..., R} of vertices, the induced subgraph is a forest.
    In any tree (or forest), the number of connected components equals:
        (number of vertices) - (number of edges).
    Thus, for the set S, we have:
        f(L, R) = |S| - (# of edges with both endpoints in S).

    2. Vertex Contribution:
    Every vertex i appears in all intervals that cover it.
    The number of intervals that include vertex i is:
        i * (N - i + 1).
    Therefore, the total contribution from vertices is:
        sum{i=1 to N} [i * (N - i + 1)].

    3. Edge Contribution:
    Consider an edge connecting vertices u and v, where we assume u < v.
    This edge appears in the induced subgraph for an interval S if and only if:
        L ≤ u and R ≥ v.
    The number of such intervals is:
        u * (N - v + 1).
    Since each such edge reduces the connected component count by 1,
    the total reduction due to edges is:
        sum{over edges (u, v) with u < v} [u * (N - v + 1)].

    4. Final Answer:
    The answer is the total vertex contribution minus the total edge contribution:
        Answer = (sum{i=1}^{N} [i * (N - i + 1)])
                    - (sum{over all edges (u, v), u < v} [u * (N - v + 1)]).
*/
void solve()
{
    ll n; cin>>n;
    ll edgescont = 0;
    for(int i = 0; i< n-1; i++)
    {
        ll u, v; cin>>u>>v;
        if(u > v)
            swap(u, v);
        
        edgescont += ( u * ( n - v + 1));
    }

    int vertexcont = 0;
    for(int i = 1; i <= n; i++)
    {
        vertexcont += i * (n - i + 1);
    }
    // cout<<edgescont<<nl;
    cout<<vertexcont - edgescont<<nl;
    


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