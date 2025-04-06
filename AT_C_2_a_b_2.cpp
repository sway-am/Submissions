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

 
using namespace std;
typedef int ll;


int isqrt(int x) {
    int low = 0, high = (int)1e9 + 10; 
    int ans = 0;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(mid * mid <= x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

/*
Explanation:

We are given a number `n`, and we want to count how many integers `X` in the range [1, n]
can be expressed in the form:
    X = 2^a × b^2
where:
    - a ≥ 1 (a is a positive integer)
    - b ≥ 1 (b is a positive integer)

Observation:
------------
Any such number X can be uniquely represented as:
    X = 2^c × d^2
where:
    - c ≥ 1
    - d is an odd positive integer

Why?
----
Because b could be even or odd, and any even b can be written as b = 2^k × d,
with d being odd. So:
    b^2 = (2^k × d)^2 = 2^(2k) × d^2
    X = 2^a × 2^(2k) × d^2 = 2^(a + 2k) × d^2 = 2^c × d^2

So instead of checking all possible pairs (a, b), we iterate over all possible c (starting from 1),
and for each c, count how many odd integers d satisfy:
    X = 2^c × d^2 ≤ n

Rewriting:
----------
We want:
    d^2 ≤ n / (2^c)

Let R = n / (2^c)
Then the maximum valid value of d is:
    D = floor(sqrt(R))

We then count how many odd integers are in the range [1, D]:
    count = (D + 1) / 2

Final Answer:
-------------
Sum this count for all c where 2^c ≤ n.

Optimization:
-------------
- We use bit shifting for 2^c: (1LL << c)
- We use an integer-based square root function (isqrt) to avoid floating point errors for large n (up to 1e18)

This approach avoids Time Limit Exceeded (TLE) and works efficiently even for very large inputs.
*/
void solve() {
    int n;
    cin >> n;
    int answer = 0;
    
    
    for (int c = 1; ; c++) {
      
        if ((1LL << c) > n) break;
        
        
        int R = n / (1LL << c);
        if(R <= 0) break;
        
        
        int D = isqrt(R);
        if(D < 1) break;
        
     
        answer += (D + 1) / 2;
    }
    
    cout << answer << "\n";
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