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
/*
    Standard Binary search, the search space is MEX
*/

 
using namespace std;
typedef int ll;

vector<int>v;
ll n, k;
bool check(int x) {
    int seg = 0;
    int cnt = 0;
   
    vector<bool> seen(x, false);
    
  
    for (auto it : v) {
        if (it < x) {
            if (!seen[it]) {
                seen[it] = true;
                cnt++;
            }
        }
     
        if (cnt == x) {
            seg++;
            
           
            for(int i =0 ; i< x; i++)seen[i] = false;
            cnt = 0;
        }
    }
    
    return seg >= k;
}
 
void solve() {
    cin >> n >> k;
    v.assign(n, 0);
    vin(v, n);
    
    
    
    map<int, int>mp;
    for(auto it:v)mp[it]++;
    int x = 0;
    while(mp[x] != 0)
    {
        x++;
    }
    int l = 0;
    int r = x;

    int ans = 0;
    
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (check(m)) {
            ans = m;  
            l = m + 1;  
        } else {
            r = m - 1;
        }
    }
    
    cout << ans << nl;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t =1;
  cin>>t;
  while(t--){
    solve();


  }
  return 0;
}