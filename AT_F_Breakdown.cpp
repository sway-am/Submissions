//DNB
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define nl "\n"
#define F first
#define S second
#define vin(v, n) for(int i = 0; i < n; i++){ cin >> v[i]; }
#define all(v) v.begin(), v.end()
#define space " "
#define int long long int

using namespace std;
typedef int ll;

vector<int> dp;
/*
 EDITORIAL WAS REFFERED
    We are given a graph with vertices, each having a weight W and an initial number of pieces.
An operation consists of removing a piece from vertex x (with weight W[x]) and then placing pieces
on some of its adjacent vertices y, provided that:
  1. W[y] < W[x], and
  2. The total sum of weights of the chosen neighbors is less than W[x].

We define dp[x] as the maximum number of operations (steps) that can be performed starting from a single piece at vertex x. 
This is given by the recurrence:

    dp[x] = 1 + max { sum(dp[y]) } 
              over any subset S of neighbors y (with W[y] < W[x]) 
              such that sum(W[y] for y in S) < W[x].

The “+1” accounts for the operation at vertex x itself.
Since the allowed moves are only to neighbors with strictly smaller weights, the dependencies are acyclic.

For a fixed vertex x, we form “items” from valid neighbors, where each item represents a neighbor y:
  - cost = W[y] (this "cost" is used in the capacity constraint)
  - value = dp[y] (the contribution from the neighbor)

The constraint is that the total cost of chosen items must be less than W[x]. 
We set the capacity to W[x] - 1 and solve a 0/1 knapsack problem to maximize the sum of dp[y] values.

We use a recursive function rec(node, W, adj) to compute dp[node] with memoization.
Inside rec, we construct the list of valid neighbor items and then call a recursive dfs() (with memoization) to solve the knapsack sub-problem.
Finally, the answer is obtained by summing, over all vertices, (initial pieces at vertex) * (dp[vertex]).
*/

int dfs(int i, int lim, vector<pair<int, int>> &items, vector<vector<int>> &memo) {
    if(i == items.size()) return 0;
    if(memo[i][lim] != -1) {
        return memo[i][lim];
    }
    // Option 1: skip the current item.
    int ans = dfs(i + 1, lim, items, memo);
    // Option 2: take the current item (if capacity allows).
    if(lim >= items[i].F) {
        ans = max(ans, items[i].S + dfs(i + 1, lim - items[i].F, items, memo));
    }
    return memo[i][lim] = ans;
}

int rec(int node, vector<int> &W, vector<vector<int>> &adj) {
    if(dp[node] != -1) {
        return dp[node];
    }

    vector<pair<int, int>> items;
    
    for(auto nb : adj[node]) {
        if(W[nb] < W[node])
            items.push_back({W[nb], rec(nb, W, adj)});
    }
    
    int best = 0;
    
    if(!items.empty()) {
        vector<vector<int>> memo(items.size(), vector<int>(W[node], -1));
        best = dfs(0, W[node] - 1, items, memo);
    }
    
    dp[node] = best + 1;  
    return dp[node];
}

void solve() {
    int n, m; 
    cin >> n >> m; 
    
    dp.clear();
    dp.resize(n, -1);
    
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v; 
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    

    vector<int> W(n), init(n);
    vin(W, n);
    vin(init, n);
    
    int s = 0; 
  
    for(int i = 0; i < n; i++) {
        s += init[i] * rec(i, W, adj);
    }
    
    cout << s << nl; 
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
