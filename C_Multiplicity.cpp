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

/*
    *** SAW TUTORIAL FOR THIS QUESTION ***
*/

ll MOD = 1e9 + 7;


void solve()
{
    ll n; cin>>n; vector<int>v(n);vin(v, n);

    vector<int>pos(1e6 + 10, 0);
    pos[0] = 1;

    for(int i = 0; i < n; i++)
    {
        vector<int>divs;
        for(int j = 1; j*j <= v[i]; j++)
        {
            if((v[i]%j) == 0)
            {
                divs.push_back(j);
                if(j != v[i]/j)
                {
                    divs.push_back(v[i]/j);
                }
            }
        }
         sort(divs.begin(), divs.end());
         reverse(divs.begin(), divs.end());
            for(auto it:divs)
            {
                pos[it] += (pos[it-1]);
                pos[it] %= MOD;
            }
    }

    int ans =0 ;
    for(auto it:pos)
    {
        ans += it;
    }
    cout<<(ans-1)%MOD<<nl;


}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t =1;
//   cin>>t;
  while(t--){
    solve();


  }
  return 0;
}