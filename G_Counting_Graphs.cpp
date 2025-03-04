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

const int mod =  998244353;
 
using namespace std;
typedef int ll;


/*
    answer is product over all u to v (s - (maxwt from u to v) + 1)
    sort everthing by edge wt and just solve
    when connecitng 2 comp
    paths possible are s1*s2 -1
    where s1 and s2 are teh size of the two comp
*/



ll binpow(ll a, ll n) {
    if (n == 0) return 1;
    if (n % 2 == 0) return binpow(a * a % mod, n / 2);
    else return a * binpow(a, n - 1) % mod;
}




struct DSU {
    vector<int> parent, size, rank;
    bool useSize;

    DSU(int n, bool useSize = true) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);
        this->useSize = useSize;
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        return parent[x] = (parent[x] == x) ? x : find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;

        if (useSize) {
            if (size[x] < size[y]) {
                parent[x] = y;
                size[y] += size[x];
            } else {
                parent[y] = x;
                size[x] += size[y];
            }
        } else {
            if (rank[x] < rank[y]) {
                parent[x] = y;
            } else if (rank[x] > rank[y]) {
                parent[y] = x;
            } else {
                parent[y] = x;
                rank[x]++;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

void solve() {
    int n, s;
    cin >> n >> s;
    DSU dsu(n);
    

    vector<array<int,3>> edges;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    

    sort(all(edges));
    
    ll ans = 1;
    for (auto &e : edges) {
        int w = e[0], u = e[1], v = e[2];

        int pu = dsu.find(u);
        int pv = dsu.find(v);
        
        
        ll nopth = dsu.size[pu] * dsu.size[pv] - 1;
        
       
        ans = ans * binpow(s - w + 1, nopth) % mod;
        

        dsu.unite(u, v);
    }
    
    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}