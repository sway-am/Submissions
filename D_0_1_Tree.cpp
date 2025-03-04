// DNB
// C++ Final Solution for Codeforces 0-1-Tree Problem (Count of Valid Pairs)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
    For each DSU0 (0‑edge) component, add s(s−1).
    For each DSU1 (1‑edge) component, add s(s−1).
    For every vertex (dsu0.compSize[z0] -1)*(dsu1.compSize[z1] -1)

    first connect all 1 component
    connect all 2 components
    then join them
*/
struct DSU {
    vector<int> parent, compSize;
    DSU(int n) {
        parent.resize(n+1);
        compSize.resize(n+1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find(int a) {
        if (parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    void unionn(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (compSize[a] < compSize[b])
            swap(a, b);
        parent[b] = a;
        compSize[a] += compSize[b];
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    

    vector<tuple<int,int,int>> edges;
    for (int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    

    DSU dsu0(n+1);
    for (auto &edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;
        if (w == 0)
            dsu0.unionn(u, v);
    }
    
    
    
    long long ans = 0;
 
    vector<bool> processed(n+1, false);
    for (int i = 1; i <= n; i++){
        int root = dsu0.find(i);
        if (!processed[root]){
            processed[root] = true;
            int s = dsu0.compSize[root];
            ans += s*(s-1);
        }
    }
    
    DSU dsu1(n+1);
    for (auto &edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;
        if (w == 1)
            dsu1.unionn(u, v);
    }
    vector<bool> processed1(n+1, false);
    for (int i = 1; i <= n; i++){
        int root = dsu1.find(i);
        if (!processed1[root]){
            processed1[root] = true;
            int s = dsu1.compSize[root];
            ans += s*(s-1);
        }
    }
    


    for(int i = 1; i<= n;i++)
    {
        int z0 = dsu0.find(i);
        int z1 = dsu1.find(i);
        ans += (dsu0.compSize[z0] -1)*(dsu1.compSize[z1] -1);
    }

    // for (auto &edge : edges) {
    //     int u, v, w;
    //     tie(u, v, w) = edge;
    //     if (w == 1) {
    //         int ru = dsu0.find(u), rv = dsu0.find(v);
    //         int u1 = dsu1.find(u); int v1 = dsu1.find(v);

    //         ans += (dsu0.compSize[ru]-1)*dsu1.compSize[v1] +( dsu0.compSize[rv]-1)*dsu1.compSize[u1];
    //         ans += 2*(dsu1.compSize[u1])*(dsu1.compSize[v1]) ;

    //         dsu1.unionn(u1, v1);
    //     }
    // }
    
    cout << ans << "\n";
    return 0;
}
