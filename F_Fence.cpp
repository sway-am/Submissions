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
const int INF = 100000000;
 
int N;
int A, B;
int H[204];
int memo[2][204][40004];
int go(int last_col, int pos, int red, int green) {
   if (red > A || green > B) return INF;
   if (pos >= N)
      return 0;
 
   int& res = memo[last_col][pos][red];
   if (res < 0) {
      res = INF;
      // paint red board at position pos
      int cur1 = go(0, pos+1, red+H[pos], green);
      if (last_col != 0)
         cur1 += min(H[pos], H[pos-1]);
      res = min(res, cur1);
      
      // paint green board at position pos
      int cur2 = go(1, pos+1, red, green+H[pos]);
      if (last_col != 1)
         cur2 += min(H[pos], H[pos-1]);
      res = min(res, cur2);
   }
   return res;
}
 
int func() {
   int res = INF;
   if (H[0] <= A) {
      memset(memo, -1, sizeof(memo));
      int cur = go(0, 1, H[0], 0);
   // fprintf(stderr, "cur = %d\n", cur);
      res = min(res, cur);
   }
   if (H[0] <= B) {
      memset(memo, -1, sizeof(memo));
      int cur = go(1, 1, 0, H[0]);
   // fprintf(stderr, "cur = %d\n", cur);
      res = min(res, cur);
   }
   return res;
}


void solve()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    scanf("%d %d", &A, &B);
    for (int i = 0; i < N; ++i)
        scanf("%d", H+i);
    int res = func();
    printf("%d\n", res >= INF ? -1 : res);


}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1    ;
//   cin>>t;
  while(t--){
    solve();


  }
  return 0;
}