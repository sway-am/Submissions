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

      
    Quadrant Fill Order:
        1. Top-left
        2. Bottom-right
        3. Bottom-left
        4. Top-right

    Base Case (n = 1, 2x2 matrix):
        [1 4]
        [3 2]

    Recursive Case (n > 1):
        - Divide the current 2^n x 2^n matrix into 4 quadrants of size 2^(n-1) x 2^(n-1).
        - Each quadrant contains (2^(n-1))^2 = 4^(n-1) = cnt values.
        - Based on (x, y), determine which quadrant the cell lies in:
              Top-left      -> quadrant 0 -> offset 0 * cnt
              Bottom-right  -> quadrant 1 -> offset 1 * cnt
              Bottom-left   -> quadrant 2 -> offset 2 * cnt
              Top-right     -> quadrant 3 -> offset 3 * cnt
        - Recursively compute the value in that submatrix and add the offset.

    Function: gv(x, y, n)
    --------------------------------------------
    Input: 
        - x, y: 0-indexed row and column in 2^n x 2^n matrix
        - n: current level of the matrix (2^n x 2^n)
    Output:
        - Integer value at (x, y)
    Recurrence:
        value(x, y, n) = q * cnt + value(x', y', n - 1)
        where (x', y') are coordinates inside the sub-quadrant and q is its index (0 to 3)

    Function: gc(d, n)
    --------------------------------------------
    Input: 
        - d: target value (1-indexed)
        - n: current level (matrix size = 2^n x 2^n)
    Output:
        - Pair (x, y): 0-indexed coordinates of value d
    Recurrence:
        - Determine quadrant q: q = (d - 1) / cnt
        - Determine position inside quadrant: d' = (d - 1) % cnt + 1
        - Get coordinates (x', y') = gc(d', n - 1)
        - Adjust based on quadrant:
            q = 0: return (x', y')
            q = 1: return (x' + half, y' + half)
            q = 2: return (x' + half, y')
            q = 3: return (x', y' + half)

    Complexity:
        - Each function performs O(n) operations per query due to recursion depth.

    Notes:
        - All coordinates and values are adjusted to 0-based indexing inside the recursive functions.
        - Inputs/outputs are converted as needed (e.g., printing 1-based coords in main).
*/

 
using namespace std;
typedef int ll;

int gv(int x, int y, int n)
{
    if(n == 1)
    {
        if(x == 0 && y == 0) return 1;
        if(x == 0 && y == 1) return 4;
        if(x == 1 && y == 1) return 2;
        if(x == 1 && y == 0) return 3;
    }

    int hlf = 1 << (n - 1);
    int cnt = hlf * hlf;

    int nexx, nexy;
    int q;
    if(x < hlf && y < hlf)  
    {
        q = 0; 
        nexx = x; 
        nexy = y;
    }
    else if(x < hlf && y >= hlf)  
    {
        q = 3;
        nexx = x; 
        nexy = y - hlf;
    }
    else if(x >= hlf && y >= hlf) 
    {
        q = 1;
        nexx = x - hlf;
        nexy = y - hlf;
    }
    else if(x >= hlf && y < hlf)  
    {
        q = 2;
        nexx = x - hlf;  
    }

    return q * cnt + gv(nexx, nexy, n - 1);
}

pair<int , int> gc(int d, int n)
{
    if(n == 1)
    {
        if(d == 1) return {0, 0};
        if(d == 2) return {1, 1};
        if(d == 3) return {1, 0};
        if(d == 4) return {0, 1};
    }

    int hlf = 1<<(n-1);
    int cnt = hlf*hlf;

    int q = (d-1)/cnt;
    int rem = (d-1)%cnt;

    pair<int, int> sub = gc(rem + 1, n - 1);
    int sub_x = sub.first, sub_y = sub.second;

    if(q == 0) 
    {
        return {sub_x, sub_y};
    } 
    else if(q == 1) 
    { 
        return {sub_x + hlf, sub_y + hlf};
    } 
    else if(q == 2) 
    { 
        return {sub_x + hlf, sub_y};
    } 
    else if(q == 3)
    { 
        return {sub_x, sub_y + hlf};
    }
}


void solve()
{
    ll n; cin>>n;
    ll q; cin>>q;

    while(q--)
    {
        string c; cin>>c;
        if(c == "->")
        {
            ll x, y; cin>>x>>y;
            x--; y--;
            cout<<gv(x, y, n)<<nl;
        }
        else
        {
            ll d; cin>>d;
            auto p = gc(d, n);
            int x = p.F; int y = p.S;
            cout<<x+1<<space<<y+1<<nl;
        }
    }

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