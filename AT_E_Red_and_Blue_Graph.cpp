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
  even number of nodes with odd degreee must be taken. rest is ismplementation
*/
long long modPow(long long base, long long exp, long long mod) {
  long long result = 1;
  base %= mod;
  while(exp > 0) {
      if(exp & 1) result = (result * base) % mod;
      base = (base * base) % mod;
      exp >>= 1;
  }
  return result;
}

// Precompute factorials and inverse factorials up to n
void precomputeFactorials(int n, vector<long long>& fact, vector<long long>& invfact) {
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
      fact[i] = (fact[i - 1] * i) % MOD;
  }
  // Compute inverse factorial using Fermat's little theorem
  invfact[n] = modPow(fact[n], MOD - 2, MOD);
  for (int i = n; i >= 1; i--) {
      invfact[i - 1] = (invfact[i] * i) % MOD;
  }
}

// Computes nCk modulo MOD using precomputed factorials
long long nCk(int n, int k, const vector<long long>& fact, const vector<long long>& invfact) {
  if(k < 0 || k > n) return 0;
  return ((fact[n] * invfact[k]) % MOD * invfact[n - k]) % MOD;
}


void solve()
{
  ll n, m, k; cin>>n>>m>>k;
  vector<long long> fact(n + 10), invfact(n + 10);
  precomputeFactorials(n+10, fact, invfact);

  vector<int>deg(n+1, 0);
  for(int i =0 ; i < m; i++)
  {
    ll u, v; cin>>u>>v;
    deg[u]++;
    deg[v]++;
  }

  int odd = 0;
  for(auto it:deg)
  {
    if(it%2)
      odd++;
  }
  

  int ans =0 ;
  for(int i = 0; i<= k; i+= 2)
  {
    if(i <= odd && n-odd >= k-i)
    {
      ans += nCk(odd, i, fact, invfact) * nCk(n - odd, k - i, fact, invfact) % MOD;

    }
  }
  cout<<ans%MOD<<nl;

}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  // cin>>t;
  while(t--){
    solve();


  }
  return 0;
}