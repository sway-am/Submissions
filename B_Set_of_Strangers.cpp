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
    ll n, m; cin>>n>>m;
    vector<vector<int>>v;
    for(int i = 0; i<n; i++)
    {
        vector<int>temp(m);
        vin(temp,m);
        v.push_back(temp);
    }


    map<int, int>mp;
    for(int i =0 ; i<n; i++)
    {
        for(int j =0 ; j<m; j++)
        {
            if(mp.find(v[i][j])==mp.end())
            {
                mp[v[i][j]] = 0;
            }
            if(i+1 < n)
            {
                if(v[i][j] == v[i+1][j])
                {
                    if(mp[v[i][j]] == 0)
                    {
                        mp[v[i][j]] = 1;
                    }
                }
            }

            if(j +1 <m)
            {
                if(v[i][j] == v[i][j+1])
                {
                    if(mp[v[i][j]] == 0)
                    {
                        mp[v[i][j]] = 1;
                    }
                    continue;
                }
            }
            
        }
    }


    int maxi = 0;
    int tot = 0;

    for(auto it:mp)
    {
        // cout<<it.first<<space<<it.second<<endl;
        tot += (it.second+1 );
        maxi = max(maxi, it.second+1);
    }

    cout<<tot - maxi<<nl;


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