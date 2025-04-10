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
#define INF (ll)1e+15
const int MOD = 998244353;
/*
  Easy - should have done in contest.

  Basically we find the b[i] with the maximum number of matches.
  then we keep selecting that string n time;

  this garuntees us that the entire arr c = b[i] now

  so that is n operations.

  now select the strings which were not a match and erase them. but the
  trick here is not to erase all the wrong matches at once.

  erase the first mis match, erase it now select the b[i] which had a 
  match for that index.
  this gurantees that the remaining n-x positions can be filled in 2*(n-x)
  operations
*/

using namespace std;
typedef int ll;


void solve()
{

  ll n, m; cin>>n>>m;
  vector<string>a(n);
  vin(a, n);
  // for(auto it:a)cout<<it<<space;
  // cout<<nl;
  vector<vector<string>>b(m, vector<string>(n));
  

  for(int i =0 ;i < m ;i++)
    for(int j = 0; j< n; j++)
      cin>>b[i][j];
    
  // for(int i = 0; i <m; i++)
  // {
  //   for(int j = 0; j < n; j++)
  //   {
  //     cout<<b[i][j]<<space;
  //   }cout<<nl;
  // }

  int mat = 0;
  vector<bool>found(n, false);

  for(int i =0 ; i< m; i++)
  {
    int cnt =0 ;
    for(int j =0; j <n ; j++)
    {
      // cout<<b[i][j]<<space<<a[j]<<nl;
      if(b[i][j] == a[j])
      {
        found[j] = true;
        cnt++;
      }
    }
    // cout<<cnt<<nl;
    mat= max(mat, cnt);
  }

  for(auto it:found)
    if(!it) {cout<<-1<<nl;return;}
  
    cout<<n + (n-mat)*2<<nl;

    


}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t =1;
  cin>>t;
  while(t--){
    solve();


  }
  return 0;
}