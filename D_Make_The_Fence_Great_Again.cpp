#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define nl "\n"
#define F first
#define S second
#define vin(v, n) for (int i = 0; i < n; i++) { cin >> v[i]; }
#define all(v) v.begin(), v.end()
#define space " "
#define int long long int

using namespace std;
typedef int ll;

/*
    notice that no number has to be increased more than twie. because you can check front and back and then worst case you have to increase it twice.
    Now just make a dp of 3XN. how much to increase , index.
    Now check all combnation of preious and current a[i]. and consider the cases only where they are not equal.
    --> struggled to write the recursive code for writing all possible combinations
    --> Tabulation is easier
*/

void solve() {
    ll n; 
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    
    vector<vector<int>> dp(3, vector<int>(n + 1, LLONG_MAX));
   

    
    dp[0][1] = 0;
    dp[1][1] = b[1];
    dp[2][1] = 2 * b[1];

    
    for (int i = 2; i <= n; i++) {
        for (int x = 0; x <= 2; x++) {
            for (int y = 0; y <= 2; y++) {
                if (a[i] + x != a[i - 1] + y) {
                    dp[x][i] = min(dp[x][i], dp[y][i - 1] + x * b[i]);
                }
            }
        }
    }

    
    cout << min({dp[0][n], dp[1][n], dp[2][n]}) << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
    