#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LIMIT = 1e12;
const ll SQRT_LIMIT = 1e6; // because N = (p^a * q^b)^2 and must be <= 1e12

// Sieve to compute primes up to n
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute primes up to 1e6.
    // However, as argued, we only really need primes up to ~1000 for the smaller factor p.
    int maxPrimeForP = 1000;
    vector<int> primes = sieve(maxPrimeForP); // for p
    vector<int> allPrimes = sieve(1000000);     // for q (if needed)

    // We can use "allPrimes" but note: when p < q and p * q <= 1e6, p is limited.
    vector<ll> nums;
    
    // For each prime p (we use the primes list up to maxPrimeForP)
    for (int i = 0; i < (int)primes.size(); i++){
        int p = primes[i];
        // For q, we need primes greater than p.
        // We can iterate through allPrimes and start from the first prime > p.
        for (int j = 0; j < (int)allPrimes.size(); j++){
            int q = allPrimes[j];
            if(q <= p) continue;
            // The smallest possible product is p * q. If that's already > SQRT_LIMIT, break.
            if ((ll)p * q > SQRT_LIMIT) break;
            // Now, for exponents a, b >= 1 such that p^a * q^b <= 1e6.
            ll pa = p;
            for (int a = 1; pa <= SQRT_LIMIT; a++){
                ll qb = q;
                for (int b = 1; qb <= SQRT_LIMIT / pa; b++){
                    ll prod = pa * qb; // p^a * q^b
                    ll N = prod * prod; // squared, so <= 1e12
                    nums.push_back(N);
                    qb *= q;
                }
                pa *= p;
            }
        }
    }
    
    // Remove duplicates and sort
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    // Process Q queries
    int Q;
    cin >> Q;
    while(Q--){
        ll A;
        cin >> A;
        // Binary search: largest number in nums that is <= A.
        int idx = upper_bound(nums.begin(), nums.end(), A) - nums.begin() - 1;
        cout << nums[idx] << "\n";
    }
    
    return 0;
}
