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
const int MOD = 998244353;
/*
Sol explained by soumya:
    We only measure up to \( k \) because the problem asks for the number of
    ways to form the exact sum \( k \). In our DP array,
    each index \( i \) (from \( 0 \) to \( k \)) represents the sum that
    can be achieved by some subset of numbers, and we don't care about sums
    greater than \( k \) since they won't contribute to the answer.
    By limiting our DP array to size \( k+1 \), we both focus our computation 
    on the sums of interest and optimize the memory and time usage,
    ensuring that each operation only updates the necessary parts of the DP state.
*/

void solve(){
    ll n, k; 
    cin >> n >> k;
    
    vector<int> dp(k+1, 0);
    dp[0] = 1;  // Initialize the empty subset
    
    while(n--){
        char c;
        int x;
        cin >> c >> x;
        if(c == '+'){
            for(int i = k-x; i >= 0; i--){
                dp[i+x] = (dp[i+x] + dp[i]) % MOD;
            }
        }
        else if(c == '-'){
            
            for(int i = x; i <= k; i++){
                dp[i] = (dp[i] - dp[i - x] + MOD) % MOD;
            }
        }
        cout << dp[k] % MOD << nl;
    }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t =1 ;
//   cin>>t;
  while(t--){
    solve();


  }
  return 0;
}