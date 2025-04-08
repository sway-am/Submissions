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


void solve()
{
    string s; cin>>s;
    int n = s.length();
    vector<int>nonzer;
    int cnt =0 ;
    for(int i = 0; i< n; i++)
    {
        nonzer.push_back(cnt);
        if(s[i] != '0')
            cnt++;
    }

    for(int i =0 ; i < n; i++)
    {
        nonzer[i] += (n - i - 1);
    }

    int ans = INT_MAX;
    for(int i = 0; i< n; i++)
    {
        if(s[i] == '0') continue;
        ans = min(ans, nonzer[i]);
    }
    
    cout<<ans<<nl;

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