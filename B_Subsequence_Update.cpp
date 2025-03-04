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


void solve() 
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> b, c;
    for (int i = 1; i < l; i++) {
        b.push_back(a[i]);
    }
    for (int i = r + 1; i <= n; i++) {
        c.push_back(a[i]);
    }
 
    int sum = 0;
    vector<int> arr;
    for (int i = l; i <= r; i++) {
        sum += a[i];
        arr.push_back(a[i]);
    }
    sort(arr.begin(), arr.end(), greater<int>());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    
    int res1 = sum, res2 = sum;
    for (int i = 0; i < arr.size() && i < b.size(); i++) {
        if (arr[i] <= b[i]) break;
        res1 -= (arr[i] - b[i]);
    }
    for (int i = 0; i < arr.size() && i < c.size(); i++) {
        if (arr[i] <= c[i]) break;
        res2 -= (arr[i] - c[i]);
    }
    int res = min({res1, res2, sum});
    cout << res << endl;
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