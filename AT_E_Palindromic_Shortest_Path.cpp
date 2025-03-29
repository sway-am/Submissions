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
Each valid transition from state (x, y) to state (k, l) represents a composite move that 
involves two independent steps: one that changes the row (from x to k) and one that 
changes the column (from y to l). Each individual step has a cost of 1. Therefore, when 
both steps are taken, the total cost for the composite move is 1 + 1 = 2. This is why 
adj[k][l] is updated as adj[x][y] + 2.
*/



void solve() {
    ll n; 
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
   
    const int INF = 1e9;
    vector<vector<int>> adj(n, vector<int>(n, INF));
    
    queue<pair<int,int>> q;

    for (int i = 0; i < n; i++) {
        adj[i][i] = 0;
        q.push({i, i});
    }
    
  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
        {  
            if (v[i][j] != '-') 
            {
                if (i == j or v[i][j] == '-') continue;
                
                adj[i][j] = 1;
                q.push({i, j});
               
            }
        }
    }
    
  
    while (!q.empty()) {
        int x = q.front().F;
        int y = q.front().S;
        q.pop();
        
        
        for (int k = 0; k < n; k++) {
            for (int l = 0; l < n; l++) {
                if (v[k][x] != '-' && v[y][l] != '-' &&
                    v[k][x] == v[y][l] && adj[k][l] == INF) {
                    adj[k][l] = adj[x][y] + 2; // kx + yl 
                    q.push({k, l});
                }
            }
        }
    }
    
    // Output the resulting matrix.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (adj[i][j] == INF ? -1 : adj[i][j]) << space;
        }
        cout << nl;
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