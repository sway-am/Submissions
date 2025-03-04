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
int Nmax = 200000 + 5;

const int multif = 499122177;
vector<long long> p2(Nmax+1, 0), inv2(Nmax+1, 0);



void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
      cin >> a[i];
  }

  vector<int> prefix(n+1, 0);
  for (int i = 0; i < n; i++){
      prefix[i+1] = prefix[i] + (a[i] == 2);
  }

  long long S = 0;
  long long countOnes = 0;
  long long ans = 0;

  for (int i = 0; i < n; i++){
      if(a[i] == 1){
          S = (S + inv2[prefix[i+1]]) % MOD;
          countOnes++;
      } else if(a[i] == 3){
          long long factor = p2[prefix[i]];
          long long cur = (factor * S) % MOD;
          cur = (cur - countOnes) % MOD;
          if(cur < 0) cur += MOD;
          ans = (ans + cur) % MOD;
      }
  }

  cout << ans % MOD << "\n";


}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  p2[0] = 1;
  for (int i = 1; i <= Nmax; i++){
      p2[i] = (p2[i-1] * 2) % MOD;
  }
  long long inv2_val = 499122177; 
  inv2[0] = 1;
  for (int i = 1; i <= Nmax; i++){
      inv2[i] = (inv2[i-1] * inv2_val) % MOD;
  }

  ll t;
  cin>>t;
  while(t--){
    solve();


  }
  return 0;
}