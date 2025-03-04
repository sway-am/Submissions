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

    int s = 0; 
    for(auto it:v)
    {
        s += it;
    }

    if(s%3 != 0)
    {
        cout<<0<<nl;
        return;
    }


    int tar = s/3;
    int tar2 = 2* tar;
    int cnt1 = 0;
    int cnt2 = 0;
    int s1 = 0;
    // // if(s1  == tar)
    // // {
    // //     cnt1++;
    // // }
    // for(int i = 0; i< n-2; i++)
    // {
    //     s1 += v[i];
    //     if(s1  == tar)
    //     {
    //         int s2 = 0; 
    //         for(int j = i+1; j < n-1; j++)
    //         {
    //             s2 += v[j];
    //             if(s2 == tar)
    //             {
    //                 cnt1++;
    //             }
    //         }
            
    //     }
    // }

    // cout<<cnt1<<nl;
    for(int i = 0; i<= n-2; i++)
    {
        int it = v[i];
        s1+= it;
        if(s1 == tar2)
        {
            cnt2 += cnt1;
        }

        if(s1 == tar)
        {
            cnt1++;
        }
    }

    cout<<cnt2<<nl;






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