// DNB
// C++ Optimized
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define nl "\n"
#define int long long int
using namespace std;

/*
  Connect all the circle centers to each other and the edge weight is 
  going to be the exposed distance between them, the starting and the ending 
  point can be added as circle with 0 centers and then use dijsktra
*/

double calcdis(int x1, int y1, int r1, int x2, int y2, int r2) {
    double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) - r1 - r2;
    return max(0.0, dist);  // Ensure non-negative distances
}

void solve() {
    int xs, ys, xe, ye;
    cin >> xs >> ys >> xe >> ye;
    
    int n;
    cin >> n;
    
    vector<tuple<int, int, int>> cents;
    cents.emplace_back(xs, ys, 0);
    
    for (int i = 0; i < n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        cents.emplace_back(x, y, r);
    }
    
    cents.emplace_back(xe, ye, 0);
    int totalNodes = n + 2;

    
    vector<vector<pair<int, double>>> adj(totalNodes);
    
    
    for (int i = 0; i < totalNodes; i++) {
        auto [x1, y1, r1] = cents[i];
        for (int j = i + 1; j < totalNodes; j++) {
            auto [x2, y2, r2] = cents[j];
            double dist = calcdis(x1, y1, r1, x2, y2, r2);
            adj[i].emplace_back(j, dist);
            adj[j].emplace_back(i, dist);
        }
    }

    
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    vector<double> dist(totalNodes, DBL_MAX);
    
    dist[0] = 0.0;
    pq.emplace(0.0, 0);
    
    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (node == totalNodes - 1) {
            cout << fixed << setprecision(10) << d << nl;
            return;
        }

        if (d > dist[node]) continue;

        for (auto [next, weight] : adj[node]) {
            double newDist = d + weight;
            if (newDist < dist[next]) {
                dist[next] = newDist;
                pq.emplace(newDist, next);
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
