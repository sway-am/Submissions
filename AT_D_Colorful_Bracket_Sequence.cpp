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
    string s; cin>>s;
    int n = s.length();

    bool ans = true;
    stack<int>st;
    vector<int>cnt = {0, 0, 0};
    map<char,int>mp;
    mp['('] = 0;
    mp['['] = 1;
    mp['<'] = 2;

    map<char,int>mp2;
    mp2[')'] = 0;
    mp2[']'] = 1;
    mp2['>'] = 2;
    bool pos = true;

    for(int i =0 ; i < n; i++)
    {
        if(mp.find(s[i]) != mp.end())
        {
            st.push(mp[s[i]]);
            cnt[mp[s[i]]]++;
            continue;
        }

        if(mp2.find(s[i]) != mp2.end())
        {
            if(st.empty() || mp2[s[i]]!= st.top())
            {
                pos = false;
                break;
            }
            else
            {
                cnt[mp2[s[i]]]--;
                st.pop();
            }

            for(auto it:cnt)
            if(it<0) {pos = false;break;}
            continue;
            
        }

    }

    if(!pos)cout<<"No"<<nl;
    else if(st.empty())cout<<"Yes"<<nl;
    else cout<<"No"<<nl;

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