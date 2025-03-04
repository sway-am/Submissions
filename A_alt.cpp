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


void solve()
{
  int n;
        cin >> n;
        string u = to_string(n);
        int q = u.size();
        vector<string>ve(9);
        for (int i = 1; i <= 8; i++) {
            string s = ve[i - 1];
            s += u[(i - 1) % (int) u.size()];
            ve[i] = s;
        }
        vector<pair<int, int>>ans;
        for (int a = 1; a <= 10000; a++) {
            int mul = a * n;
            for (int j = 1; j <= 8; j++) {
                int g = stoi(ve[j]);
                int b = mul - g;
                if (b == 0)continue;
                // int q = to_string(b).size();
                 // if (b == 18 && a == 20)D(n - q);
                if (j == a * q - b) {
                    ans.push_back({ a,b });
                }
            }
        }
        //D(ans.size());
      //  for (auto [a, b] : ans)D(a), D(b);
        cout << ans.size() << "\n";
        for (auto [a, b] : ans)cout << a << ' ' << b << "\n";
    
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