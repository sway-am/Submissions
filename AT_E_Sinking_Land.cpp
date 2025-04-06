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



 
using namespace std;
typedef int ll;

struct DSU {
    vector<int> parent, compSize;
    DSU(int n) {
        parent.resize(n);
        compSize.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x) {
        return parent[x] = (parent[x] == x ? x : find(parent[x]));
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        parent[y] = x;
        compSize[x] += compSize[y];
    }
    int size(int x) {
        return compSize[find(x)];
    }
};
 

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
 
struct Cell {
    int elev;
    int id; // id = i*w + j
};
 
int h, w, Y;
bool valid(int ni, int nj)
{
    return ni >= 0 && ni < h && nj >= 0 && nj < w;
}
void solve(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    cin >> h >> w >> Y;
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            cin >> grid[i][j];
        }
    }
    
   
    vector<Cell> cells;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int id = i * w + j;
            cells.push_back({grid[i][j], id});
        }
    }
    sort(cells.begin(), cells.end(), [](const Cell &a, const Cell &b){
        return a.elev < b.elev;
    });
    
    // DSU: total nodes = h*w + 1, where dummy index = h*w.
    int total = h*w;
    int dummy = total; 
    DSU dsu(total + 1);
    
  
    vector<bool> activated(total, false);
        
    // Pointer to cells array.
    int ptr = 0;
    int nCells = cells.size();
    
    // Precompute whether a cell is on boundary.
    vector<bool> isBoundary(total, false);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int id = i*w+j;
            if(i==0 || i==h-1 || j==0 || j==w-1)
                isBoundary[id] = true;
        }
    }
    
    // For each water level (year), process newly flooded cells.
    // We'll output safe area = total cells - (size of dummy component - 1)
    // (we subtract 1 because dummy is not an actual cell)

    for (int lev = 1; lev <= Y; lev++){
        
        while(ptr < nCells && cells[ptr].elev <= lev)
        {
            int id = cells[ptr].id;
            activated[id] = true;

            // If on boundary, union with dummy.
            if(isBoundary[id])
                dsu.unite(id, dummy);

            // Compute grid position.
            int i = id / w, j = id % w;

            // Check all 4 neighbors.
            /*
                This is the tricky part, here we even when the cell is not
                a boundary we still go and process it and mark it as valid
                and check all of its neighbours and union that node with the neighbours.activated
                Note: 
                This is because even though the cell is not a boundary,
                it still can be part of a larger flooding area that we still need to consider.
            */
            for (int d = 0; d < 4; d++)
            {
                int ni = i + dx[d], nj = j + dy[d];

                if(valid(ni, nj))
                {
                    int nid = ni*w + nj;
                    if(activated[nid]){
                        dsu.unite(id, nid);
                    }
                }
            }
            ptr++;
        }
        
        int flooded = dsu.size(dummy) - 1; // minus dummy itself
        cout << (total - flooded) << "\n";
    }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
//   cin>>t;
  while(t--){
    solve();


  }
  return 0;
}