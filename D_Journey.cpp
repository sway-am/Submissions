// DNB
// C++
// Needed hint 
/** 
 construct two graph, one for even move and one for odd move and then connect the 
 nodes in between them, then use dsu and solve, the size of each parent is the answer.
**/ 
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

const int N = 6e5 + 10;
const int K = 3e5 + 5;

int parent[N+10];
int siz[N+10];

int find_par(int i) {
    // Path compression
    if (parent[i] != i) {
        parent[i] = find_par(parent[i]);
    }
    return parent[i];
}

void Union(int a, int b)
{
    int par_a = find_par(a);
    int par_b = find_par(b);

    if(par_a == par_b)
    {
        return;
    }

    if(siz[par_a] >= siz[par_b])
    {
        swap(par_a, par_b);
    }

    siz[par_b] += siz[par_a];
    parent[par_a] = par_b;
    return;
}

void clearDSU(int n)
{
    for(int i =0 ; i<= n; i++)
    {
        parent[i] = i;
        siz[i] = 1;
        parent[i+K] = i+K;
        siz[i+K] = 1;
    }
}



void solve()
{
    int n; cin>>n;
    string s; cin>>s;

    clearDSU(n);

    for(int i = 0; i<n; i++)
    {
        if(s[i] == 'L')
        {
            // (i+1)e->(i)o
            Union(i+1, i +K);
        }
        else
        {
            // ie->(i+1)o
            Union(i, i + K +1);
        }
    }

    for(int i = 0; i<=n; i++)
    {
        int p = find_par(i);
        cout<<siz[p]<<space;
    }

    cout<<nl;


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