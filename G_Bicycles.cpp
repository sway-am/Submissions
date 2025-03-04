#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
 
#define nl "\n"
#define int long long
/*
    When a new state is generated (i.e., reaching a node with a given "cycl" value and time),
    we check if we have already reached that node with the same "cycl" value 
    at a lower cost. 
    If the new state is better, 
    it might lead to a better solution along future paths, 
    so we push it into the priority queue. 
    If not, we discard it to avoid unnecessary worry
*/
 
// State holds: current time, current node, and the current "cycl" value.
struct State {
    int time;
    int node;
    int cycl;
};
 

struct StateCompare {
    bool operator()(const State &a, const State &b) {
        return a.time > b.time;
    }
};
 
void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; 
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    
    vector<int> slw(n);
    for (int i = 0; i < n; i++){
        cin >> slw[i];
    }
    
    int goal = n - 1;
    
    
    priority_queue<State, vector<State>, StateCompare> pq;
    
    pq.push({0, 0, slw[0]});
    
    
    vector<map<int, int>> best(n);
    best[0][slw[0]] = 0;
    
    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();
        
        int curTime = cur.time;
        int node = cur.node;
        int cycl = cur.cycl;
        
       
        if (node == goal) {
            cout << curTime << nl;
            return;
        }
        
        
        if (best[node].find(cycl) != best[node].end() && best[node][cycl] < curTime)
            continue;
        
       
        for (auto &edge : adj[node]) {
            int nxt = edge.first;
            int w = edge.second;
            int newTime = curTime + w * cycl;
            
            
            int newCycl = cycl;
            if (best[nxt].find(newCycl) == best[nxt].end() || best[nxt][newCycl] > newTime) {
                best[nxt][newCycl] = newTime;
                pq.push({newTime, nxt, newCycl});
            }
            
          
            newCycl = slw[nxt];
            if (best[nxt].find(newCycl) == best[nxt].end() || best[nxt][newCycl] > newTime) {
                best[nxt][newCycl] = newTime;
                pq.push({newTime, nxt, newCycl});
            }
        }
    }
    
    
    cout << -1 << nl;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
