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
    vector<vector<ll>> ar(5001, vector<ll>(5001, 0));
    vector<vector<ll>> res(5001, vector<ll>(5001, 0));


    int l , r , q;
	
	
	for(int i = 1; i<= n; i++)
    { 
        cin>>ar[1][i] , res[1][i] = ar[1][i];
	}

	for(int i=2;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			ar[i][j] = ar[i-1][j] ^ ar[i-1][j+1];
			res[i][j] = max(ar[i][j] , max(res[i-1][j] , res[i-1][j+1]));
		}
	}
	
	cin>>q;
	
	while(q--){
		cin>>l>>r;
		
		int row = r - l + 1;
		int col = l;
		
		cout<<res[row][col]<<endl;
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