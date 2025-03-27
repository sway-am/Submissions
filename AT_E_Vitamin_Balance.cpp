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
/*
    use knapsack and find how many vit for each cal value you can get
    dp1[cal] represents the number of vit 1 you can get such that total cal is
    cal.

    then use binary search to find the minimum number of pills
*/
 
using namespace std;
typedef int ll;
ll n, X; 
vector<ll> v, a, c;
ll dp1[5050];
ll dp2[5050];
ll dp3[5050];


void solve() {
    cin >> n >> X;
    v.clear(); a.clear(); c.clear();
    v.resize(n); a.resize(n); c.resize(n);
    for (int i = 0; i < n; i++){
        cin >> v[i] >> a[i] >> c[i];
    }
    
    // Initialize dp arrays: dp[k][cal] = maximum vitamin sum achievable using foods of that vitamin type with exactly 'cal' calories.
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    memset(dp3, -1, sizeof(dp3));
    dp1[0] = dp2[0] = dp3[0] = 0;
    
    
    for (int i = 0; i < n; i++){
        if(v[i] != 1) continue;
        for (int cal = X; cal >= c[i]; cal--){
            if(dp1[cal - c[i]] != -1){
                dp1[cal] = max(dp1[cal], dp1[cal - c[i]] + a[i]);
            }
        }
    }
    
    
    for (int i = 0; i < n; i++){
        if(v[i] != 2) continue;
        for (int cal = X; cal >= c[i]; cal--){
            if(dp2[cal - c[i]] != -1){
                dp2[cal] = max(dp2[cal], dp2[cal - c[i]] + a[i]);
            }
        }
    }
    
    // Process vitamin type 3 foods.
    for (int i = 0; i < n; i++){
        if(v[i] != 3) continue;
        for (int cal = X; cal >= c[i]; cal--){
            if(dp3[cal - c[i]] != -1){
                dp3[cal] = max(dp3[cal], dp3[cal - c[i]] + a[i]);
            }
        }
    }
    
    ll max1 = 0, max2 = 0, max3 = 0;
    for (int i = 0; i <= X; i++){
        max1 = max(max1, dp1[i]);
        max2 = max(max2, dp2[i]);
        max3 = max(max3, dp3[i]);
    }
    ll high = min({ max1, max2, max3 }) + 1;
    ll low = 0, ans = 0;
    while(low <= high) {
        ll mid = low + (high - low) / 2;
        ll totalCal = 0;
        
        // For dp1: find minimum calories needed to reach at least 'mid'
        bool found = false;
        for (int i = 0; i <= X; i++){
            if(dp1[i] >= mid) { totalCal += i; found = true; break; }
        }
        if(!found) totalCal += X + 1; // not achievable
        
        // For dp2:
        found = false;
        for (int i = 0; i <= X; i++){
            if(dp2[i] >= mid) { totalCal += i; found = true; break; }
        }
        if(!found) totalCal += X + 1;
        
        // For dp3:
        found = false;
        for (int i = 0; i <= X; i++){
            if(dp3[i] >= mid) { totalCal += i; found = true; break; }
        }
        if(!found) totalCal += X + 1;
        
        // If the total calories needed is within X, then mid is achievable.
        if(totalCal <= X) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << ans << "\n";
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