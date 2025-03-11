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

bool isPowerOfTwo(long long n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int highestSetBit(int n) {
    if (n == 0) return -1; 
    return 31 - __builtin_clz(n); 
}

// Function to compute 2^highest_set_bit - 1
int computeValue(int n) {
    int x =  1;
    for(int i = 0; i< n; i++)
    {
        x*= 2;
    }

    return x-1;
}


void solve()
{
    ll n; cin>>n;
    if(isPowerOfTwo(n)|| isPowerOfTwo(n+1))
    {
        cout<<-1<<nl;
        return;
    }

    int x = highestSetBit(n);
    cout<<computeValue(x)<<nl;





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