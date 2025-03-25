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
    vector<int>v(7);
    vin(v, 7);
    map<int, int>mp;
    for(auto it:v) mp[it]++;
    bool tr = false;
    bool two = false;

    for(int i = 1; i <= 13; i++)
    {
        if(mp[i] >= 3)
        {
            for(int j = 1; j<= 13; j++)
            {
                if(i!=j && mp[j] >= 2)
                {
                    cout<<"Yes"<<nl;
                    return;
                }
            }
        }
    }
    
    cout<<"No"<<nl;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t =1 ;
//   cin>>t;
  while(t--){
    solve();


  }
  return 0;
}