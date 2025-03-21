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
/*
        Step 1: Determine the number of digits (len)
    -------------
    - Let K be the given number (read into variable n).
    - For 1-digit numbers, there are exactly 9 possibilities (digits 1..9).
    - For any number with len digits:
        • The first digit has 9 choices (cannot be 0).
        • Every subsequent digit has 9 choices as well (all 10 digits except the digit equal to the previous one).
    Thus, the total count of len-digit Neq Numbers is 9^len.
    
    - The code initializes:
        pos = 9  (this represents the count for the current length)
        len = 1

    - Then it uses a while-loop:
        while (n > pos) {
            n -= pos;      // Subtract the number of Neq Numbers with the current digit length
            len++;         // Increase the digit length
            pos *= 9;      // Update pos to 9^(len)
        }
    After the loop, len is the number of digits of the K-th Neq Number, and n now represents the offset within the block of numbers with that many digits.
    
    - Finally, pos is divided by 9 so that it becomes 9^(len-1), which will be used as the count of possibilities for each subsequent digit.

    Step 2: Construct the answer digit-by-digit
    -------------
    - Initialize:
        res = 0 (this will hold the final number)
        pop = 0 (this holds the previous digit; note: for the first digit, since 0 is not allowed, the inner loop skips j==0 because pop is initially 0)

    - For each digit position i from 1 to len:
        • For each candidate digit j from 0 to 9:
            - If j equals the previous digit (pop), skip it to satisfy the “adjacent digits must be different” rule.
            - Each choice for digit j would allow 9^(remaining positions) numbers to be formed.
            - If the remaining offset n is greater than pos (which is the count for each candidate):
                -> Subtract pos from n and try the next candidate.
            - Otherwise, digit j is the one for the current position:
                -> Append j to the result (res = res * 10 + j).
                -> Update pop = j (so that the next digit will not be equal to j).
                -> Break out of the inner loop.
        • Then, update pos by dividing it by 9 (since the number of possibilities for each remaining position decreases by a factor of 9).

    Step 3: Output the result
    -------------
    - After processing all digit positions, res contains the K-th smallest Neq Number.
    - The result is then printed.
*/

void solve()
{
    ll n; cin>>n;
    ll pos = 9;
    int len = 1;
    while(n > pos)
    {
        n -= pos;
        len++;
        pos *= 9;
    }

    int res = 0;
    int pop = 0;
    pos /= 9;

    for(int i = 1; i <= len; i++)
    {
        for(int j = 0; j <= 9; j++)
        {
            if(j == pop ) continue;

            if(n > pos)
            {
                n -= pos;
            }
            else
            {
                res = res*10 + j;
                pop = j;
                break;
            }
        }

        pos /= 9;
    }

    cout<<res<<nl;



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