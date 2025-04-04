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
#define INF (ll)1e+15
const int MOD = 998244353;

/*DSU easy*/

 
using namespace std;
typedef int ll;
struct DSU {
    vector<int> parent, size, rank;
    bool useSize = true;
    DSU(int n, bool useSize = true) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);
        this->useSize = useSize;
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        return parent[x] = (parent[x] == x) ? x : parent[x] = find(parent[x]);
    }

    int findsiz(int x)
    {
        int par = find(x);
        return size[par];
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

void solve()
{
    ll n; cin>>n;
    vector<int>v(n);
    vin(v, n);
    vector<int>d(n);
    vin(d, n);

    DSU dsu(n+1);

    for(int i = 0 ;i < n; i++)
    {
        dsu.unite(i+1, v[i]);
    }

    vector<int>ans;
    int curr = 0;
    
    for(int i = 0; i< n; i++)
    {
        if(!dsu.connected(0, v[d[i] -1]))
        {
            curr += dsu.findsiz(d[i]);
            dsu.unite(0, d[i]);
            ans.push_back(curr);
        }
        else
        {
            ans.push_back(curr);
        }

    }

    for(auto it:ans)
    {
        cout<<it<<space;
    }
    cout<<nl;





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