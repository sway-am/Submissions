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

 
using namespace std;
typedef int ll;

long long binpow(long long a, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) return binpow(a * a % MOD, n / 2);
    else return a * binpow(a, n - 1) % MOD;
}

vector<int>powers;
int tot ;

void solve()
{

    ll n; cin>>n;
    tot =0 ; 
    for(auto it:powers)
        tot += it;
    int p = 38;

    while(p >=0  && tot >= n)
    {
        if(tot - powers[p] >= n)
        {
            tot -= powers[p];
        }
        p--;
    }

    cout<<tot<<nl;


}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t =1;
  cin>>t;


  powers.push_back(1);
  for(int i = 1; i <= 38; i++)
  {
    powers.push_back(powers[powers.size()-1]*3);
  }
  

  



  while(t--){
    solve();


  }
  return 0;
}