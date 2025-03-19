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
    Explanation of the Solution:

    Problem Recap:
    ---------------
    We are given a grid with dimensions h x w and m bombs. Each bomb has:
      - A row number r[i]
      - A column number c[i]
      - A power value a[i]
    
    The goal is to compute a value dp[i] for each bomb that represents the maximum “chain length” (or number of moves)
    you can achieve starting from that bomb. The move from one bomb to another is allowed only if the target bomb is in the
    same row or same column and has a strictly higher power (a[i]). That is, a bomb can jump only to bombs with greater power.

    Key Observations:
    -----------------
    1. Since a bomb can only jump to bombs with a strictly higher power, processing bombs in descending order of power
       ensures that when processing a bomb, all bombs that can be jumped to (i.e., with higher power) are already processed.
       
    2. Bombs with the same power should not influence each other’s dp values because the move is allowed only to bombs with
       strictly higher power. Thus, we must process bombs with the same power as a group. For each such group, we:
         - First compute the dp values for each bomb in the group without updating the state (so they don't see each other’s values).
         - Then update the state arrays so that bombs with lower power (processed later) can use these computed dp values.

    Data Structures Used:
    -----------------------
    - A map (mp) to group bombs by their power:
         Key: power value a[i]
         Value: vector of bomb indices having that power.
      The map sorts keys in increasing order, so later we reverse the group order to process from highest to lowest power.

    - Two state arrays, rmax and cmax:
         rmax[r] stores the maximum dp value (plus 1) among bombs in row r that have already been processed.
         cmax[c] stores the maximum dp value (plus 1) among bombs in column c that have already been processed.
      These arrays allow us to quickly look up the best available chain length from the same row or column.

    - A dp array that stores the answer for each bomb (the maximum chain length starting from that bomb).

    Detailed Processing Steps:
    ----------------------------
    1. Input and Grouping:
       - Read each bomb’s row, column, and power.
       - Insert the bomb's index into the map mp under the key a[i].
         This groups all bombs with the same power together.

    2. Reversing the Groups:
       - Extract the groups from the map into a vector of vectors.
       - Reverse the order of this vector so that the first group corresponds to the bombs with the highest power.
         This allows us to process bombs from highest power to lowest.

    3. Initialization of State:
       - Initialize rmax and cmax arrays with size (h + 1) and (w + 1) respectively, setting all values to 0.
       - Initialize the dp array for all m bombs with 0.

    4. Processing Each Group:
       For each group (which contains bombs with the same power), perform the following two passes:

       a. First Pass - Compute dp Values:
          - For each bomb in the current group (using its index idx):
              dp[idx] = max( rmax[ r[idx] ], cmax[ c[idx] ] )
          This calculates the best possible move from the bomb, using only bombs with strictly higher power
          (which have been processed earlier). The maximum is taken from the row and column state arrays.

       b. Second Pass - Update the State Arrays:
          - For each bomb in the group (again, index idx):
              Update rmax[ r[idx] ] = max( rmax[ r[idx] ], dp[idx] + 1 )
              Update cmax[ c[idx] ] = max( cmax[ c[idx] ], dp[idx] + 1 )
          The addition of 1 represents making a move from the current bomb.
          This update ensures that bombs with lower power (processed later) will consider the chain length starting from
          these bombs.

    5. Output:
       - After processing all groups, the dp array contains the answer for each bomb.
       - Output the dp values in the original order of input.

    Complexity:
    -----------
    - Grouping bombs and reversing the group vector is O(m log m) due to map insertion and sorting.
    - Processing each bomb once gives O(m).
    Overall, the solution runs efficiently with a time complexity of O(m log m).

    Summary:
    --------
    The solution uses dynamic programming combined with a clever ordering strategy:
      - Process bombs from highest to lowest power.
      - Use two passes for each group of bombs with the same power to avoid interference.
      - Maintain state arrays for each row and column to quickly retrieve the best chain length so far.
    This approach ensures that the computed dp value for each bomb correctly reflects the maximum chain of moves possible
    according to the problem's constraints.
*/



void solve()
{
    ll h, w, m; cin>>h>>w>>m;
    map<int, vector<int>>mp;
    vector<int>r(m);
    vector<int>c(m);
    vector<int>a(m);

    for(int i = 0; i< m; i++)
    {
        cin>>r[i]>>c[i]>>a[i];
        mp[a[i]].push_back(i);
    }

    vector<vector<int>>v;
    for(auto it:mp)
    {
        v.push_back(it.S);
    }

    // reverse(all(v));
    vector<int> rmax(h + 1, 0);
    vector<int> cmax(w + 1, 0);

    vector<int>dp(m, 0);

    for(int i = v.size() - 1; i >= 0; i--)
    {
        for(auto idx : v[i])
        {
            dp[idx] = max(rmax[r[idx]], cmax[c[idx]]);
        }

        for(auto idx : v[i])
        {
            rmax[r[idx]] = max(rmax[r[idx]], 1 + dp[idx]);
            cmax[c[idx]] = max(cmax[c[idx]], 1 + dp[idx]);
        }

    }

    for(auto it:dp)
    {
        cout<<it<<nl;
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