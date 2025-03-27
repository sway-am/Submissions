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




bool check(int bench, int n, int m, int k)
{
    ll fullCycles = m / (bench + 1);
    ll rem = m % (bench + 1);
    int count = fullCycles * bench + min(rem, bench);
    if(n * count >= k) return true;

    return false;
}

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    
    ll lo = 1, hi = m, ans = -1;
    
    while (lo <= hi) 
    {
        ll mid = (lo + hi) / 2;
        if (check(mid, n, m, k)) 
        {
            ans = mid;
            hi = mid - 1; 
        } 
        else 
        {
            lo = mid + 1; 
        }
    }
    
    cout << ans << "\n";


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