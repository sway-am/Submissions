// DNB
// C++
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define nl "\n"
#define int long long int

using namespace std;
typedef int ll;
/*
    Used a priority queue to keep on the highest stamina
    and also a dp array to check if i have ever reached that node with a higher power.
    If i have then i dont need to process furher, i can just leave from there
    else i have to process the node.
*/

void solve() {
    int n, m, k; 
    cin >> n >> m >> k;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
    vector<int> dp(n+1, -1);

    
    priority_queue<pair<int,int>> pq;
    
    for (int i = 0; i < k; i++) {
        int v, s; 
        cin >> v >> s;
        if (dp[v] < s) {
            dp[v] = s;
            pq.push({s, v});
        }
    }
    
    while (!pq.empty()) {
        auto [power, node] = pq.top();
        pq.pop();
        
        if (dp[node] != power) continue;
        
        if (power == 0) continue; 
        for (auto neighbor : adj[node]) {
            
            if (dp[neighbor] < power - 1) {
                dp[neighbor] = power - 1;
                pq.push({dp[neighbor], neighbor});
            }
        }
    }
    

    vector<int>ans;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] >= 0) {count++;ans.push_back(i);}
    }
    cout << count << nl;
    for(auto it:ans)
    {cout<<it<<" ";}
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
