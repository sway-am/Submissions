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
vector<pair<int, int>> mov = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

/*
    Everthing is easy but the main thing is the code where once you mark
    any cell as '+' you go and visit the adjcent cells again regardless if you have
    visited them previously or not.

    This is best shown by the example

    3 2
    .#
    ..
    L.
*/
void solve()
{
    ll n, m; cin>>n>>m;

    vector<vector<char>>v;

    for(int i = 0; i < n; i++)
    {
        vector<char>temp(m);
        vin(temp, m);
        v.push_back(temp);
    }


    int r =0 ; int c= 0 ;
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(v[i][j] == 'L')
            {
                r = i; c = j;
                break;
            }
        }
    }


    vector<vector<int>>vis(n, vector<int>(m, 0));

    queue<pair<int ,int>>q;
    if(r +1 < n && v[r + 1][c] == '.')
    {
        q.push({r+1, c});
    }
    if(r - 1 >= 0 && v[r-1][c] == '.')
    {
        q.push({r-1, c});
    }
    if(c +1 < m && v[r][c+1] == '.')
    {
        q.push({r, c+1});
    }
    if(c - 1 >= 0 && v[r][c-1] == '.')
    {
        q.push({r, c-1});
    }
    vis[r][c] = 1;

    while(!q.empty())
    {
        int i = q.front().F;
        int j = q.front().S;
        vis[i][j] = 1;
        q.pop();

        int cnt = 0;

        for(auto it:mov)
        {
            int nr = i + it.F;
            int nc = j + it.S;
            if(nr < n && nr >= 0 && nc >= 0 && nc < m)
            {
                if(v[nr][nc] == '.')
                {
                    cnt ++;
                }
            }
        }

        if( cnt < 2)
        {
            v[i][j] = '+';

            for(auto it:mov)
            {
                int nr = i + it.F;
                int nc = j + it.S;
                if(nr < n && nr >= 0 && nc >= 0 && nc < m  && v[nr][nc] == '.')
                {
                    q.push({nr, nc});
                }
            }
        }
        
    }

    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout<<v[i][j]<<"";
        }
        cout<<nl;
    }


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