// DNB - Corrected version using backward recursion
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
 
#define nl "\n"
#define int long long

struct GatePair {
    char opLeft;
    int aLeft;
    char opRight;
    int aRight;
};
 
struct Triple {
    int L, R, C;
};
 
// Recursive function: returns the optimal triple (L, R, C)
// for gates from index 'ind' to the end.
Triple rec(int ind, const vector<GatePair>& gt) {
    if(ind == gt.size()) {
        // Base state: no gates left.
        return {1, 1, 0};
    }
    // Get the state from later gates.
    Triple nxt = rec(ind + 1, gt);
    
    // Current gate parameters.
    char opL = gt[ind].opLeft;
    int aL = gt[ind].aLeft;
    char opR = gt[ind].opRight;
    int aR = gt[ind].aRight;
    
    // For a multiplication gate, we want to multiply by a;
    // note that a multiplication by a is equivalent to
    // multiplying by (a-1 + 1). For a '+' gate we only add.
    int ml = (opL == '+') ? 0 : (aL - 1);
    int add_left = (opL == '+') ? aL : 0;
    int mr = (opR == '+') ? 0 : (aR - 1);
    int add_right = (opR == '+') ? aR : 0;
    int tot_add = add_left + add_right;
    
    Triple curr;
    
    if(nxt.L >= nxt.R) {
        // Option 1: use left branch for multiplication.
        curr.L = nxt.L * (ml + 1);
        curr.R = nxt.R + nxt.L * mr;
        curr.C = nxt.L * tot_add + nxt.C;
    } else {
        // Option 2: use right branch for multiplication.
        curr.L = nxt.L + nxt.R * ml;
        curr.R = nxt.R * (mr + 1);
        curr.C = nxt.R * tot_add + nxt.C;
    }
    return curr;
}
 
void solve() {
    int n;
    cin >> n;
    vector<GatePair> gt(n);
    for (int i = 0; i < n; i++) {
        cin >> gt[i].opLeft >> gt[i].aLeft >> gt[i].opRight >> gt[i].aRight;
    }
    Triple ans = rec(0, gt);
    cout << (ans.L + ans.R + ans.C) << nl;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
