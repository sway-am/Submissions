// DNB
// C++ Optimized
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
const int INF = 1e18;

using namespace std;
typedef int ll;
/*
  for airport let us consider edge between
  Ai and n+1
  for port Ai and n+2
  And road between Ai and Bi

  now we need to have a fully connected component so we need mst, so
  we use kruskal algorithm to find the mst

  4 possibilities
  airport + roads
  port + road
  airport + port
  all three

  we check the MST wt for all 4 possible combinations
*/

struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        return parent[x] = (parent[x] == x) ? x : find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int component_size(int x) {
        return size[find(x)];
    }
};

int kruskal(vector<vector<int>>& edges, int n)
{
    DSU dsu(n+2);  // Fix: DSU up to n+2
    int mst_wt = 0;

    for(auto &it: edges)
    {
        int wt = it[0], u = it[1], v = it[2];

        if (!dsu.connected(u, v)) {
            mst_wt += wt;
            dsu.unite(u, v);
        }
    }

    return (dsu.component_size(1) < n) ? INF : mst_wt;
}

void solve()
{
    ll n, m; 
    cin >> n >> m;
    vector<int> airport(n), port(n);
    vin(airport, n);
    vin(port, n);

    vector<vector<int>> roads;
    for(int i = 0; i < m; i++)
    {
        ll u, v, w; 
        cin >> u >> v >> w;
        roads.push_back({w, u, v});  
    }

    ll ans = INF;
    vector<vector<int>> edges;

    // Trying all 4 possible combinations (like bitmask 0 to 3)
    for(int k = 0; k < 4; k++) {
        edges.clear();
        if (k & 1) for(int i = 0; i < n; i++) edges.push_back({airport[i], i+1, n+1});
        if (k & 2) for(int i = 0; i < n; i++) edges.push_back({port[i], i+1, n+2});
        for(auto &r : roads) edges.push_back(r);

        sort(all(edges));
        ans = min(ans, kruskal(edges, n));
    }

    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
