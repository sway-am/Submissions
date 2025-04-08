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
const int MOD = 998244353;
#define INF (ll)1e+15
 
using namespace std; 
typedef int ll;

/*
    The states are i, and j and dp[i][j] represents the cost to fix the segment i j;
    so now we can have a k from i to j and dp[i][j] = min dp[i][k] + dp[k+1][j]
    but if for some a[k] == a[j] we can do that whole sequence as one color and then change
    the colour later so

    if a[k] == a[j]
    dp[i][j] = dp[i][k] + dp[k+1][j-1] + j-k; we only have to do till j-1 becase the last 
    colour is now incoperated into k; 
*/


const int N = 405;
int n;
int a[2 * N];     
int c[N];         
int f[2 * N][2 * N]; 

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }


    memset(f, 0x3f, sizeof(f));

    for (int i = 1; i <= 2 * n; i++) 
    {
        f[i][i] = 1 + c[a[i]];
    }

    for (int len = 2; len <= n; len++) 
    {
        for (int i = 1; i + len - 1 <= 2 * n; i++) 
        {
            int j = i + len - 1;

            for (int k = i; k < j; k++) {
                f[i][j] = min(f[i][j] , f[i][k]+ f[k+1][j]);
            }

            for (int k = i; k < j; k++) 
            {
                if (a[k] == a[j]) 
                {
                    int cost = f[i][k] + ((k + 1 <= j - 1) ? f[k + 1][j - 1] : 0) + (j - k);
                    f[i][j] = min(f[i][j], cost);
                }
            }
        }
    }

    int ans = LLONG_MAX;
    for (int i = 1; i <= n + 1; i++) 
    {
        ans = min(ans, f[i][i + n-1]);
    }

    cout << ans << '\n';
}



signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  // cin>>t;
  while(t--){
    solve();


  }
  return 0;
}