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
  vector<int>p(n);
  vin(p, n);
  
  sort(p.begin(), p.end());
    
    
    int left = 0;
    int right = n - 1;
    bool toggle = true; 
    vector<int>q(n);
    for (int i = 0; i < n; ++i) {
        if (toggle) {
            q[i] = p[right--];
        } else {
            q[i] = p[left++];
        }
        toggle = !toggle;
    }
    
    for(int i =0 ; i< n; i++)
    {
      cout<<q[i]<<" ";
    }cout<<endl;

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