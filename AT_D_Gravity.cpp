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
// We'll group blocks by column using 1-indexing.
    // Each column is stored in a set sorted by row value.
    // In our input, each block is given as (X, Y)
    // and we want to group by column X.
    // To do that, we swap the input so that:
    // a becomes the row (Y) and b becomes the column (X).
// removalTime[i] will store the time at which block i is removed.
    // If a block is never removed, its time remains INF.
// Simulate the removal process.
    // At each "step", if every column has at least one block,
    // remove the lowest block from each column.
    // The removal time for those blocks is set to the maximum row value
    // among the selected blocks.
// Answer queries.
    // A block that is removed at time R disappears at time R + 0.5.
    // So if a query has time t (meaning at t+0.5) and t >= removalTime,
    // the block is already gone

const int INF = 1e15;
void solve(){
    int n, w;
    cin >> n >> w;
    
    vector<set<pair<int,int>>> cols(w + 1);
    
    vector<int> removalTime(n, INF);
 
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        swap(a, b);  // now, a = Y (row), b = X (column)
        cols[b].insert({a, i});
    }
 
    
    bool canRemove = true;
    while (canRemove) {
        vector<pair<int,int>> currentBlocks; // blocks to remove this step
        int currentMax = 0;
        for (int col = 1; col <= w; col++){
            if (cols[col].empty()){
                canRemove = false;
                break;
            }
            auto block = *cols[col].begin();
            currentMax = max(currentMax, block.first);
            currentBlocks.push_back(block);
        }
 
        if (!canRemove) break;
 
        // Set the removal time for each block removed in this round.
        for (auto &p : currentBlocks) {
            removalTime[p.second] = currentMax;
        }
        // Remove the blocks from each column.
        for (int col = 1; col <= w; col++){
            cols[col].erase(cols[col].begin());
        }
    }
 
    
    int q;
    cin >> q;
    while (q--){
        int t, idx;
        cin >> t >> idx;
        idx--;  // convert to 0-index
        if (t >= removalTime[idx])
            cout << "No" << "\n";
        else
            cout << "Yes" << "\n";
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