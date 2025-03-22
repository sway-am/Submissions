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
Graph Structure:
- The graph is a tree with one extra edge, so it has exactly one cycle.
- Let k be the number of vertices in the cycle and for each cycle vertex, let t be the size 
  of its attached branch (excluding the cycle vertex). Then, n = k + sum(t) over all cycle vertices.

Counting Pairs:
1. Cycle Pairs:
   - Count all pairs of cycle vertices: k * (k - 1).

2. Pairs Within Branches:
   - For a branch of size t attached to a cycle vertex, consider the branch including the 
     cycle vertex (t+1 vertices). The number of pairs in this tree is: (t+1 choose 2) = t*(t+1)/2.

3. Cross Pairs (Between Branch and Others):
   - Between branch and cycle vertices (excluding its base): 2 * t * (k - 1).
   - Between branch and vertices in other branches: t * (n - k - t).

The final answer is the sum of these contributions.
*/

int n;
int cycst = -1, cycend = -1;
set<int> cycl;
bool cyclefound = false;
vector<vector<int>> adj;
vector<int> parent;
vector<int> visited; 

// Reset global variables for each test case.
void initialize() {
    cycst = -1; 
    cycend = -1;
    cycl.clear();
    cyclefound = false;
    adj.clear();
    parent.clear();
    visited.clear();
}

// After a cycle is found via DFS, record all cycle vertices.
void storecycle() {
    if (!cyclefound) return;
    cycl.insert(cycst);
    int cur = cycend;
    while (cur != cycst) {
        cycl.insert(cur);
        cur = parent[cur];
    }
}

// DFS to detect a cycle.
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

// DFS to calculate the size of the branch attached to a cycle vertex.
// 'siz' is the number of vertices in the subtree (excluding the cycle vertex).
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
    // There are n vertices and n edges.
    adj.resize(n);
    parent.resize(n, -1);
    visited.resize(n, 0);
    
    for (int i = 0; i < n; i++) {
        int u, v; 
        cin >> u >> v;
        u--; v--; // convert to 0-indexed
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0, -1);
    if (cyclefound)
        storecycle();
    
    int k = cycl.size(); // number of vertices in the cycle
    vector<int> branchSizes;
    
    // For each cycle vertex, compute branch size t (excluding the cycle vertex)
    for (int u : cycl) {
        int t = calcsize(u, -1);
        branchSizes.push_back(t);
    }
    
    // Total vertices: n = k + (sum of all branch sizes)
    // Final answer is computed as described:
    // 1. Pairs within the cycle: k*(k-1)
    // 2. For each cycle vertex with branch size t:
    //    - Internal branch pairs: t*(t+1)/2
    //    - Branch-cycle pairs: 2*t*(k-1)
    //    - Branch-other branches pairs: t*((n-k)-t)
    int ans = k * (k - 1);
    for (int t : branchSizes) {
        int part1 = t * (t + 1) / 2;
        int part2 = 2 * t * (k - 1);
        int part3 = t * ((n - k) - t);
        ans += part1 + part2 + part3;
    }
    
    cout << ans << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin>>t;
  while(t--){
    solve();


  }
  return 0;
}