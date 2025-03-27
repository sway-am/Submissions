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
vector<bool> prime(1e7 + 20, true);
vector<int>pp;

//seive copied from gfg

void SieveOfEratosthenes()
{
    for (int p = 2; p * p <= prime.size()-1; p++)
    {
        if (prime[p] == true) 
        {
            for (int i = p * p; i <= prime.size()-1; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= prime.size()-1; p++)
        if (prime[p])
            pp.push_back(p);
}

void solve()
{
    ll n; cin>>n;
    int ans = 0;
    for(auto it:pp)
    {
        if(it <= n)
        {
            ans += n/it;
        }
    }

    cout<<ans<<nl;


}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  SieveOfEratosthenes();
  ll t;
  cin>>t;
  while(t--){
    solve();


  }
  return 0;
}