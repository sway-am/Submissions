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
    check if the graph is bipartite, as if a loop has odd number of nodes
    then it is not possible to make and meaningful arrangement.
    
    Then in every connected component find the two arrangements possible
    suppose a and b

    the final answer is 
    2^a + 2^b

    as there are two odd number 1 and 3 so the nodes have 2 options.
*/

const int MOD = 998244353;
const int Nmax = 3000005;
int cnt0 = 0;
int cnt1 = 0;

vector<int>pow2(Nmax);
vector<int> col;
bool bad;

void dfs(int v, int c, vector<vector<int>>& adj) {
    col[v] = c;
    if (c == 0) cnt0++;
    else cnt1++;
    
    for (auto to : adj[v]) {
        if (col[to] == -1) {
            dfs(to, 1 - c, adj);
        } else if (col[to] == col[v]) {
            bad = true;
        }
    }
}

bool isBipartite(vector<vector<int>>& adj, int n) {
    col.assign(n + 1, -1);
    bad = false;
    
    for (int i = 1; i <= n; i++) {
        if (col[i] == -1) {
            cnt0 = cnt1 = 0;
            dfs(i, 0, adj);
            if (bad) return false;
        }
    }
    return true;
}

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (!isBipartite(adj, n)) {
        cout << 0 << nl;
        return;
    }

    ll ans = 1;
    col.assign(n + 1, -1);
    
    for (int i = 1; i <= n; i++) {
        if (col[i] == -1) {
            cnt0 = cnt1 = 0;
            dfs(i, 0, adj);
            int res = (pow2[cnt1] + pow2[cnt0]) % MOD;
            ans = (ans * res) % MOD;
        }
    }
    cout << ans % MOD << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pow2[0] = 1;
    for (int i = 1; i < Nmax; i++) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
