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
    ll n; cin>>n;
    if(n%2 == 0) {cout<<-1<<nl; return;}

    vector<int>ans;
    for(int i = 1; i<= n; i++)
    {
        ans.push_back(2*i%n);
    }

    for(int i = 0; i< n; i++)
    {
        if(ans[i] == 0)
        ans[i] = n;
    }

    for(auto it:ans)
    {
        cout<<it<<space;
    }
    cout<<nl;


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