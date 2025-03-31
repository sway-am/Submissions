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


void solve()
{
    int a[3] = {1, 1, 1};
    int b[3] = {2, 2, 2};
    int c[3]  = a+b;



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