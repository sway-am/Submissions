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
       n = d^2 * 2^c
where:
   - d is an odd positive integer
   - c is an integer ≥ 1

=== How it works ===

For each c starting from 1:
    - Compute 2^c and divide n by it: R = n / 2^c
    - Then find the largest d such that d^2 <= R
    - Only odd values of d are valid (i.e., 1, 3, 5, ..., D)
    - Number of such odd d's is (D + 1) / 2
    - Sum up this count for each c until 2^c > n

This effectively counts how many numbers ≤ n have the structure:
    number = (odd number)^2 × power of two

=== Example ===
For n = 100:
   - c = 1 → R = 50 → D = sqrt(50) = 7 → odd d’s: 1,3,5,7 → count = 4
   - c = 2 → R = 25 → D = 5 → odd d’s: 1,3,5 → count = 3
   - c = 3 → R = 12 → D = 3 → odd d’s: 1,3 → count = 2
   - ...
Final answer = 4 + 3 + 2 + ...
*/
 
using namespace std;
typedef int ll;


const ll LIMIT = 1e12;
const ll SQRT_LIMIT = 1e6;

vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            if ((ll)i * i <= n)
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
        }
    }
    return primes;
}







void solve() 
{
    
    int maxP = 1000;
    vector<int> primes = sieve(maxP); // for p
    vector<int> allPrimes = sieve(1000000);
    
    vector<ll> nums;
    
   
    for (int i = 0; i < (int)primes.size(); i++)
    {
        int p = primes[i];
        
        for (int j = 0; j < (int)allPrimes.size(); j++)
        {
            int q = allPrimes[j];

            if(q <= p) continue;

            
            if ((ll)p * q > SQRT_LIMIT) break;
            
            ll pa = p;

            for (int a = 1; pa <= SQRT_LIMIT; a++)
            {
                ll qb = q;
                for (int b = 1; qb <= SQRT_LIMIT / pa; b++)
                {
                    ll prod = pa * qb; 
                    ll N = prod * prod; 
                    nums.push_back(N);
                    qb *= q;
                }
                pa *= p;
            }
        }
    }
    

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    

    int Q;
    cin >> Q;
    while(Q--)
    {
        ll A;
        cin >> A;
        int idx = upper_bound(nums.begin(), nums.end(), A) - nums.begin() - 1;
        cout << nums[idx] << "\n";
    }

    

    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    solve();
    return 0;
}
