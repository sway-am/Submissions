// DNB
// C++
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define nl "\n"
#define F first
#define S second
#define vin(v,n) for(int i = 0; i < n; i++){ cin >> v[i]; }
#define all(v) v.begin(), v.end()
#define space " "
#define int long long int

using namespace std;
typedef int ll;
// Explanation of the logic:
// -------------------------
// 1. The smoke originates at (0,0) at time t = 0. Then, at each time step t (from 1 to N), the smoke moves
//    in the direction indicated by the t-th character of the string S. Let P[t] be the prefix sum representing
//    the cumulative displacement from (0,0) after t moves.
// 
// 2. The smoke positions at time t+0.5 are exactly the differences between the current position P[t] and any
//    earlier prefix position P[i] for 0 <= i < t. This is because if P[t] - P[i] = (R, C), it means that the
//    smoke that was at P[i] has moved to (R, C) at time t+0.5.
// 
// 3. To determine whether (R, C) has smoke at time t+0.5, we check if there exists any prefix sum P[i] (with 0 <= i < t)
//    such that P[i] = P[t] - (R, C).
// 
// 4. We use a set to store all previously seen prefix sums. For each time step, after updating our current position,
//    we check if the position (current position - (R, C)) exists in the set. If it does, then smoke exists at (R, C)
//    at time t+0.5, and we output "Yes". Otherwise, we output "No".
// 
// 5. Finally, we insert the current prefix sum into the set and move to the next time step.
//
// The code below implements the above logic.

pair<int, int> getDelta(char ch) {
    if(ch == 'N') return {-1, 0};
    if(ch == 'S') return {1, 0};
    if(ch == 'W') return {0, -1};
    if(ch == 'E') return {0, 1};
    return {0, 0}; 
};

void solve() {
    int n, R, C; 
    cin >> n >> R >> C;
    string s; 
    cin >> s;

    set<pair<int, int>> st;
   
    st.insert({0, 0});
    
    int r = 0, c = 0;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        auto d = getDelta(s[i]);
        r += d.F;
        c += d.S;

        
        if (st.find({r - R, c - C}) != st.end()) {
            ans.push_back(1);
        } else {
            ans.push_back(0);
        }

        
        st.insert({r, c});
    }

    for (auto &it : ans)
        cout << it <<"";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
