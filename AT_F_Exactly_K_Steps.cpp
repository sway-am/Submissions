// DNB
// C++
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define nl "\n"
#define F first
#define S second
#define vin(v,n) for(int i = 0; i<n; i++){cin >> v[i];}
#define all(v) v.begin(), v.end()
#define space " "
#define int long long int

using namespace std;
typedef int ll;
/*
    A key observation is that in any tree the “diameter” (i.e. the longest distance between any two vertices) can be used to “cover” all vertices in one of two directions. In this solution, we:
*/

const int MOD = 998244353;

ll N, L, R, K;

void Calculate_Depth(vector<vector<int>>& edge, vector<int>& depth, int stnode) {
    depth[stnode] = 0;
    queue<int> q;
    q.push(stnode);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it : edge[node]) {
            if (depth[it] > depth[node] + 1) {
                depth[it] = depth[node] + 1;
                q.push(it); // Fixed: push the neighbor, not the current node.
            }
        }
    }
    return;
}

void solve() {
    cin >> N;
    vector<vector<int>> edge(N);
    for (int i = 1; i < N; i++) {
        cin >> L >> R;
        L--, R--;
        edge[L].push_back(R);
        edge[R].push_back(L);
    }

    int a = 0, b = 0;
    vector<int> adis(N, MOD);
    vector<int> bdis(N, MOD);
    
    // First BFS from node 'a' (starting at 0)
    Calculate_Depth(edge, adis, a);
    for (int i = 0; i < N; i++) {
        if (adis[i] > adis[b]) {
            b = i;
        }
    }
    
    // Second BFS from 'b'
    Calculate_Depth(edge, bdis, b);
    for (int i = 0; i < N; i++) {
        if (bdis[i] > bdis[a]) {
            a = i;
        }
    }
    
    // Reset adis and run BFS from 'a' to get the unique paths toward a.
    for (auto& i : adis) i = MOD;
    Calculate_Depth(edge, adis, a);

    // Build binary lifting tables for paths toward a and b.
    vector<vector<int>> atapi(20, vector<int>(N, -1));
    vector<vector<int>> btapi(20, vector<int>(N, -1));

    for (int i = 0; i < N; i++) {
        for (auto j : edge[i]) {
            if (adis[j] < adis[i]) {
                atapi[0][i] = j;
            }
            if (bdis[j] < bdis[i]) {
                btapi[0][i] = j;
            }
        }
    }
    
    for (int i = 1; i < 20; i++) {
        for (int j = 0; j < N; j++) {
            if (atapi[i - 1][j] != -1) {
                atapi[i][j] = atapi[i - 1][atapi[i - 1][j]];
            }
            if (btapi[i - 1][j] != -1) {
                btapi[i][j] = btapi[i - 1][btapi[i - 1][j]];
            }
        }
    }
    
    cin >> K;
    while (K--) {
        cin >> L >> R;
        L--;
        if (adis[L] >= R) {
            for (int i = 0; i < 20; i++) {
                if ((R >> i) & 1LL) {
                    L = atapi[i][L];
                }
            }
            cout << L + 1 << nl;
        }
        else if (bdis[L] >= R) {
            for (int i = 0; i < 20; i++) {
                if ((R >> i) & 1LL) {
                    L = btapi[i][L];
                }
            }
            cout << L + 1 << nl;
        }
        else {
            cout << -1 << nl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
