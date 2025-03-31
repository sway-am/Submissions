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
Pigeon Swap Problem - ABC395 D (AtCoder)

Problem Overview:
-----------------
- We have N pigeons and N nests, both numbered from 1 to N.
- Initially, each pigeon i is in nest i.
- There are Q queries of three types:
    1. Move pigeon 'a' to nest 'b'.
    2. Swap the contents (pigeons) of nest 'a' and nest 'b'.
    3. Report the current nest of pigeon 'a'.
- Note: One nest can have multiple pigeons.

Approach:
---------
To handle the operations in O(1) per query, we decouple the identity of a nest (its logical identifier)
from its actual contents using indirection with three arrays:

1. cur[i]:
   - Stores the "logical nest id" for pigeon i.
   - Initially, cur[i] = i (each pigeon is in its own nest).

2. M[j]:
   - Maps the logical nest id j to the actual nest number.
   - Initially, M[j] = j (logical nest j is the actual nest j).

3. inv[x]:
   - Inverse mapping from an actual nest number x to its corresponding logical nest id.
   - Initially, inv[x] = x.

Operation Details:
------------------
1. Move Operation (Type 1: "1 a b"):
   - Move pigeon a to nest b.
   - We update cur[a] = inv[b], meaning pigeon a now references the logical nest corresponding to actual nest b.

2. Swap Operation (Type 2: "2 a b"):
   - Swap the contents of actual nests a and b.
   - Let la = inv[a] and lb = inv[b] be the logical ids for nests a and b.
   - Swap the mappings: swap(M[la], M[lb]) and swap(inv[a], inv[b]).
   - This effectively makes all pigeons with cur value la now point to actual nest b, and vice versa.

3. Query Operation (Type 3: "3 a"):
   - Report the current actual nest of pigeon a.
   - The answer is given by M[cur[a]], as cur[a] is the logical nest id, and M maps it to the actual nest.

Time Complexity:
----------------
- Each query (move, swap, and query) is processed in O(1) time.
- This makes the solution efficient for large inputs (up to 10^6 pigeons and 3×10^5 queries).
*/

void solve()
{
    int N, Q;
    cin >> N >> Q;
    
    // cur[i]: the "logical" nest id where pigeon i currently is.
    // M[j]: the actual nest number for logical nest id j.
    // inv[x]: the logical nest id corresponding to actual nest x.
    vector<int> cur(N + 1), M(N + 1), inv(N + 1);
    for (int i = 1; i <= N; i++){
        cur[i] = i;  // initially, pigeon i is in nest i (logical id = i)
        M[i] = i;    // logical nest i corresponds to actual nest i
        inv[i] = i;  // inverse mapping: actual nest i maps to logical id i
    }
    
    while(Q--){
        int type;
        cin >> type;
        if(type == 1){
            int a, b;
            cin >> a >> b;
            cur[a] = inv[b];
        } else if(type == 2){
            int a, b;
            cin >> a >> b;
            int la = inv[a], lb = inv[b];
            
            swap(M[la], M[lb]);
            swap(inv[a], inv[b]);
        } else if(type == 3){
            int a;
            cin >> a;
            
            cout << M[cur[a]] << "\n";
        }
    }


}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t =1 ;
//   cin>>t;
  while(t--){
    solve();


  }
  return 0;
}