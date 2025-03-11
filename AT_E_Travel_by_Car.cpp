#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define space " "
#define int long long int
/*
    
    The Floyd-Warshall algorithm can be used to compute the shortest distance between all pairs of points in O(N³) time.

    First, we construct a weighted undirected graph, where each town is a vertex and each road is an edge. The weight of each edge corresponds to the road's distance in the problem.

    By applying the Floyd-Warshall algorithm to this graph, we can determine the shortest distance between all pairs of towns.

    Next, we create another graph, where each town is a vertex, and an edge of weight 1 is added between pairs of towns whose shortest distance is ≤ L.

    By applying the Floyd-Warshall algorithm again to this new graph, we can determine the minimum number of refuels required to travel between any two towns.
*/
const int INF = 1e18; 
void solve()
{
    int n, m, l;
    cin >> n >> m >> l;
    
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> cntr(n + 1, vector<int>(n + 1, INF));

    
    for (int i = 1; i <= n; i++) {
        dis[i][i] = 0;
        cntr[i][i] = 0;
    }

   
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
    }

   
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][k] < INF && dis[k][j] < INF) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && dis[i][j] <= l) {
                cntr[i][j] = 1; 
            }
        }
    }

    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cntr[i][k] < INF && cntr[k][j] < INF) {
                    cntr[i][j] = min(cntr[i][j], cntr[i][k] + cntr[k][j]);
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (cntr[u][v] < INF) {
            cout << cntr[u][v] - 1 << nl;
        } else {
            cout << -1 << nl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
