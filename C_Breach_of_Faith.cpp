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
const int limit = 1000000000000000000;


void solve()
{
    ll n; cin>>n; 
    set<int>b;
    int lar = 0;
    for(int i = 0; i < 2*n; i++)
    {
        ll temp; cin>>temp;
        b.insert(temp);
        lar = max(lar, temp);
    }

    int cntr = 1;
    int ef = 0;
    for(auto it:b)
    {
        if(cntr %2)
        {
            ef -= it;
        }
        else
        {
            ef += it;
        }

        cntr ++;
    }

    if(ef > 0 && b.find(ef) == b.end())
    {
        // cout<<"hell"<<nl;
        cout<<ef<<space;
        vector<int>ans;
        for(auto it:b)
        {
            ans.push_back(it);
        }

        for(int i = 0; i< ans.size(); i+=2)
        {
            cout<<ans[i+1]<<space<<ans[i]<<space;
        }

        cout<<nl;
        return;
    }

    //alt 
    int a1 = lar;
    b.erase(a1);

    vector<int> arr(2*n, 0);
    int ind = 1;
    for(auto it:b)
    {
        arr[ind] = it;
        ind ++;
    }

    vector<pair<int, int>> pref(2*n+1 , {0, 0}); // eve, odd
    int pro = 0;
    int pre = 0;

    // 1 -> 2n;
    for(int i = 1; i< 2*n; i++)
    {
        int it = arr[i];
        if(i %2) 
        {
            pro += it;
        }
        else
        {
            pre += it;
        }

        pref[i].F = pre;
        pref[i].S = pro;
    }
    // cout<<pro<<space<<pre<<nl;

    // for(int i =1 ; i< 2*n +1; i++)
    // {
    //     cout<<pref[i].F<<space<<pref[i].S<<nl;
    // }
    

    ef = 0;
    for(int i = 1; i< 2*n ; i+= 2)
    {
        ef = pref[i].F - pref[i].S;
        // cout<<pro<<space<<pref[i].S<<space<<pre<<space<<pref[i].F<<nl;
        // cout<<(pro - pref[i].S) - (pre - pref[i].F)<<nl;
        ef = ef +  ((pro - pref[i].S) - (pre - pref[i].F));
        

        int x = lar - ef;
        // cout<<i<<space<<x<<space<<ef<<nl;
        if(x != lar && x >= 1 && x <= limit && b.find(x) == b.end())
        {
            vector<int>ans;
            ans.push_back( lar);
            for(int  j = 1; j< i; j+= 2)
            {
                ans.push_back(arr[j+1]);
                ans.push_back(arr[j]);
            }
            // cout<<x<<space;
            ans.push_back(x);
            ans.push_back(arr[i]);
            for(int j = i+1; j < 2*n; j+=2)
            {
                // cout<<arr[j]<<space;
                ans.push_back(arr[j+1]);
                ans.push_back(arr[j]);
            }

            for(auto it:ans)
            {
                cout<<it<<space;
            }
            cout<<nl;
            return;
        }
    }





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