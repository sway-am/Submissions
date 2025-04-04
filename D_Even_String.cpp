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
const int MAX = 500000+10; 
/*
    note that for difference of indices to be even the numbers can either be
    both be in even index of both be in odd index
    Hence 
    oddcnt = (n+1)/2; evenct = n/2;

    So now we now need to devide the frequencies such that if they are taken in 
    odd index or even index. Clearly a standard dp question

    firstly find the sum of index which must be odd and cant be even. ie freq[i] > evencnt
    and if a freq is capable of being either even or odd, we store that separatly in 
    a vector called "free"

    now the remaining odd numbers will be target =  (n+1)/2 - comp. odd

    and now we calculate the number of ways we can devide free frequencies to complete target
    let that be x;

    so bassically number of ways to do assignment = x
    we now need to see the number of ways to do arrangement

    number of ways tp arrange will be (oddcnt!) * (evencnt!) /(f1! * f2! * f3!....)
    standard maths

    total ways = arrangement * assignment

    implementation was slightly difficult.
*/


 
using namespace std;
typedef int ll;

ll fact[MAX + 1], invFact[MAX + 1];

long long modexp(long long a, long long b, long long m = MOD) {
    long long res = 1;
    a %= m;
    while(b) {
        if(b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
 
// Fast exponentiation modulo mod from gfg
long long modExp(long long base, long long exp, int mod) {
    long long result = 1;
    while(exp > 0) {
        if(exp & 1)
            result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}


long long modinv(long long a, long long m = MOD) {
    return modexp(a, m-2, m);
}


void solve()
{
    vector<int>v(26);
    vin(v, 26);

    vector<int>freq;
    int tot = 0;
    for(auto it:v)
        if(it != 0) freq.push_back(it);

    for(auto it:freq) tot += it;

    ll oddcnt = (tot+1)/2;
    ll evecnt = tot/2;

    bool poss = 0;
    vector<int> free;
    int comp = 0; // must be odd wale numbers

    for(int i = 0; i< freq.size(); i++)
    {
        int f = freq[i];

        if(f > oddcnt && f > evecnt){cout<<0<<nl;return;}

        if(f > evecnt)
        {
            comp += f;
        }
        else if(f <= oddcnt && f <= evecnt)
        {
            free.push_back(f);
        }
    }

    if(comp > oddcnt){cout<<0<<nl; return;}


    int tar = oddcnt - comp;

    int m = free.size();
    vector<vector<int>> dp(m + 1, vector<int>(tar + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= m; i++) {
        int f = free[i - 1]; 
        for (int x = 0; x <= tar; x++) 
        {
            
            dp[i][x] = dp[i-1][x];
            
            if (x >= f) {
                dp[i][x] = (dp[i][x] + dp[i-1][x - f]) % MOD;
            }
        }
    }
    ll ass = dp[m][tar]%MOD;
    
    ll arr = (fact[oddcnt]*fact[evecnt])%MOD;
    for(auto it:freq)
    {
        arr = (arr * invFact[it])%MOD;
    }


    cout<<(ass*arr)%MOD<<endl;


    


}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin>>t;
// precomutation code copied from gfg

  fact[0] = 1;
    for (int i = 1; i <= MAX; i++){
        fact[i] = fact[i-1] * i % MOD;
    }
    
    // Compute inverse factorial of MAX using Fermat's little theorem:
    invFact[MAX] = modExp(fact[MAX], MOD - 2, MOD);
    
    // Use the recurrence relation to compute the rest:
    // invFact[i-1] = invFact[i] * i mod MOD.
    for (int i = MAX; i > 0; i--){
        invFact[i-1] = invFact[i] * i % MOD;
    }


  while(t--){
    solve();


  }
  return 0;
}