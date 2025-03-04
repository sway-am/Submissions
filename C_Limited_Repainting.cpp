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

bool possi(string& s, vector<int>& pen, int lim, int k) {
    int n = pen.size();
    int cntr = 0;
    bool strt = false;

    for (int i = 0; i < n; i++) {
        if (pen[i] > lim && s[i] == 'B' && !strt) 
        {
            if (!strt) 
            {
                cntr++;
                strt = true;
            }
        }

        if(strt && s[i] == 'R' && pen[i] >lim)
        {
            strt = false;
        }
    }

    return cntr <= k; 
}


void solve()
{
    ll n, k;
    cin>>n>>k;
    string des; cin>>des;
    vector<int>pen(n); vin(pen, n);

    ll mini = 0; 
    ll maxi = 0;
    for(auto it:pen)
    {
        maxi = max(maxi,it);
    }
    int ans = maxi;

    while(mini <= maxi)
    {
        int m = mini + (maxi - mini)/2;

        if(possi( des, pen, m, k))
        {
            ans = min(ans, m);
            maxi = m -1;
        }
        else
        {
            mini = m+1;
        }
    }

    cout<<ans<<nl;


    




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