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
const int MOD = 998244353;
 
using namespace std;
typedef int ll;


void solve()
{
  int n;
  cin >> n;
  int len = 2 * n;
  vector<int> a(len);
  for (int i = 0; i < len; i++){
      cin >> a[i];
  }
  
  
  vector<bool> adj(n+1, false);
  
  map<pair<int,int>, int> pairCount;
  
  
  for (int i = 0; i < len - 1; i++){
      if(a[i] == a[i+1]){
          adj[a[i]] = true;
      } else {
          int x = a[i], y = a[i+1];
          if(x > y) swap(x, y);
          pairCount[{x, y}]++;
      }
      
      if(i + 2 < len && a[i+2] == a[i]){
          i++;
      }
  }
  
  int ans = 0;
  
  for(auto &entry : pairCount){
      if(entry.second == 2){
          auto p = entry.first;
          if(!adj[p.first] && !adj[p.second])
              ans++;
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