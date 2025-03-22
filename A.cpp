// DNB
// C++
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define nl "\n"
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define int long long
using namespace std;
const int mod = 1e9+7;

int n;
int cycst = -1, cycend = -1;
set<int> cycl;
bool cyclefound = false;
vector<vector<int>> adj;
vector<int> parent;
vector<int> visited; 

// Fast binary exponentiation (no mod needed if numbers are small, but here we use mod)
long long binpow(long long a, long long b) {
    long long res = 1;
    while(b > 0) {
        if(b & 1)
            res = res * a; 
        a = a * a;
        b >>= 1;
    }
    return res;
}

void initialize() {
    cycst = -1; 
    cycend = -1;
    cycl.clear();
    cyclefound = false;
    adj.clear();
    parent.clear();
    visited.clear();
}

void storecycle() {
    if (!cyclefound) return;
    cycl.insert(cycst);
    int cur = cycend;
    while (cur != cycst) {
        cycl.insert(cur);
        cur = parent[cur];
    }
}

void dfs(int node, int par) {
    visited[node] = 1; 
    parent[node] = par;
    for (int nxt : adj[node]) {
        if (nxt == par) continue;
        if (visited[nxt] == 1) { 
            cycend = node;
            cycst = nxt;
            cyclefound = true;
            return;
        }
        if (visited[nxt] == 0) {
            dfs(nxt, node);
            if(cyclefound) return;
        }
    }
    visited[node] = 2; 
}

int calcsize(int node, int par) {
    int siz = 0;
    for (int nxt : adj[node]) {
        if (nxt == par || cycl.count(nxt)) continue;
        siz += 1 + calcsize(nxt, node);
    }
    return siz;
}

void solve() {
    initialize();
    cin >> n;
    adj.resize(n);
    parent.resize(n, -1);
    visited.resize(n, 0);
    for (int i = 0; i < n; i++) {
        int u, v; 
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0, -1);
    if (cyclefound)
        storecycle();
    
    
    vector<int> comp;
    for (int u : cycl) {
        int siz = calcsize(u, -1);
        comp.push_back(siz + 1); // include u itself
    }
    
    int tot = 0;
    for (auto T : comp) {
        tot += T;
    }
    int ans = 0;
    for (auto T : comp) {
        ans += (T - 1);
        ans += binpow(2, tot - T - 1);
    }

    
    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}