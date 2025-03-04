#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
 
#define nl "\n"
#define int long long

/*
  A priority queue always picks the city with the smallest current cost.
  When a city is added, if its parent is -1, it means we built a power plant there; otherwise, we connect it with its parent.
  For every unprocessed city, we update the best connection cost if connecting via the newly added city is cheaper.
*/
void solve() {
    int n;
    cin >> n;
    
    
    vector<pair<int,int>> coord(n);
    for (int i = 0; i < n; i++) {
        cin >> coord[i].first >> coord[i].second;
    }
    
    
    vector<int> costPlant(n);
    for (int i = 0; i < n; i++) {
        cin >> costPlant[i];
    }
    
    
    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    
    
    const int INF = 1e18;
    vector<int> minCost(n, INF);   
    vector<int> parent(n, -1);     
    vector<bool> inMST(n, false);
    
    
    for (int i = 0; i < n; i++) {
        minCost[i] = costPlant[i];
    }
    
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({minCost[i], i});
    }
    
    int totalCost = 0;
    vector<int> powerPlants;              // Cities where we build a power plant
    vector<pair<int,int>> connections;    // Connections between cities (u, v)
    
    while (!pq.empty()) {
        auto [curCost, u] = pq.top();
        pq.pop();
        
        
        if (inMST[u]) continue;
        inMST[u] = true;
        totalCost += curCost;
        
        
        if (parent[u] == -1) {
            powerPlants.push_back(u);
        } else {
            connections.push_back({parent[u], u});
        }
        
        
        for (int v = 0; v < n; v++) 
        {
            if (!inMST[v]) 
            {
                int connectionCost = (k[u] + k[v]) * 
                    (abs(coord[u].first - coord[v].first) + abs(coord[u].second - coord[v].second));
                
                if (connectionCost < minCost[v]) 
                {
                  minCost[v] = connectionCost;
                  parent[v] = u;
                  pq.push({minCost[v], v});
                }
            }
        }
    }
    
 
    cout << totalCost << nl;
    cout << powerPlants.size() << nl;
    sort(powerPlants.begin(), powerPlants.end());
    for (auto city : powerPlants) {
        cout << city + 1 << " "; 
    }
    cout << nl;
    
    cout << connections.size() << nl;
    for (auto [u, v] : connections) {
        cout << u + 1 << " " << v + 1 << nl;
    }
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
