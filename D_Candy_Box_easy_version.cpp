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
    vector<int>v(n);
    vin(v, n);
    map<int, int>mp;
    for(auto it:v)
    {
        mp[it]++;
    }

    vector<int>freq;
    for(auto it:mp)
    {
        // cout<<it.F<<space<<it.S<<nl;
        freq.push_back(it.second);
    }

    sort(all(freq));
    // reverse(all(freq));
    int maxi = freq[freq.size()-1];

    int s =0 ;
    for(int i = freq.size()-1; i>=0; i--)
    {
        s += min(maxi, freq[i]);
        maxi = min(maxi, freq[i]);
        maxi -= 1;
        if(maxi == 0)
        {
            break;
        }
    }

    cout<<s<<nl;
    
    



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