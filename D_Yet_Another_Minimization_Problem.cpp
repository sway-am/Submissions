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
    Replaced previously accepted, cumbersome array variable changing with 2D dp. Core logic remains same.
    1D dp cannot be used because when dp[x] = 1; in start of the loop same thing can be used again in that loop only.
    which gives wrong answer

    Calculate effective formula.

    The Problem with Direct Updates (dp[j - a[i] + b[i]] = 1):
        If you update dp directly inside the nested loop, you risk using new states that were just added during the same iteration, which leads to incorrect results. This can create unintended propagation and invalidate the intended dynamic programming approach.

        Example Scenario
        Consider dp[j] = 1, and you're processing:

        j - a[i] + b[i] = X
        If you immediately set dp[X] = 1, the next loop might also read from dp[X], even though it’s supposed to only use "old" states from the previous iteration.

        This incorrectly uses freshly computed states when iterating forward.


*/

void solve() {
    ll n;
    cin >> n;
    vector<int> a(n), b(n);
    vin(a, n);
    vin(b, n);

    int s1 = 0, s2 = 0;
    for (auto it : a) s1 += it;
    for (auto it : b) s2 += it;

    const int MAX_SUM = 30005;
    vector<vector<int>> dp(n + 1, vector<int>(MAX_SUM, 0));

    dp[0][s1] = 1; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAX_SUM; j++) {
            if (dp[i][j]) {
                int new_pos = j - a[i] + b[i];
                if (new_pos > 0 && new_pos < MAX_SUM) {
                    dp[i + 1][new_pos] = 1;
                }
                dp[i + 1][j] = 1;  
            }
        }
    }

    ll ans = 0;
    for (auto it : a) ans += it * it;
    for (auto it : b) ans += it * it;

    ans = (n - 2) * ans;
    int res = LLONG_MAX;

    for (int i = 1; i < MAX_SUM; i++) {
        if (dp[n][i]) {
            int S1 = i;
            int S2 = s1 + s2 - S1;
            res = min(res, ans + S1 * S1 + S2 * S2);
        }
    }

    cout << res << nl;
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