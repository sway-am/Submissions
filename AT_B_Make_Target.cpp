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
    vector<vector<int>>grid(n+1, vector<int>(n+1, 0));

    for(int i = 1; i<= n; i++)
    {
        int j = n + 1 - i;
        if(i <= j)
        {
            for(int r = i; r <= j; r++)
            {
                for(int c = i; c<= j; c++)
                {
                    if(i%2 == 1) grid[r][c] = 1;
                    else grid[r][c] = 0;
                }
            }
         }
    }

    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(grid[i][j] == 1) cout<<'#'<<"";
            else cout<<'.'<<"";
        }

        cout<<nl;
    }


}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
//   cin>>t;
  while(t--){
    solve();


  }
  return 0;
}