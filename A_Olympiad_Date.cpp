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

    //01032025
    int required[10] = {0};
    required[0] = 3; 
    required[1] = 1; 
    required[2] = 2; 
    required[3] = 1; 
    required[5] = 1; 
    
    vector<int>count(10, 0); 
    int answer = 0;
    
    for (int i = 1; i <= n; i++){
        int digit = v[i-1];
        count[digit]++;
        
           
        bool canForm = true;
        for (int d = 0; d < 10; d++){
            if (count[d] < required[d]){
                canForm = false;
                break;
            }
        }
        
        if (canForm && answer == 0) {
            answer = i;
            break;
        }
    }
    
    cout << answer<<nl;;

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