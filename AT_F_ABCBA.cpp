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
 /*
We want to find the longest palindromic suffix of a given string s.
A palindromic suffix is a substring that starts at some index and goes to the end of s, and is also a palindrome.

Key observations:
-----------------
1. Let s be the input string and t be its reverse.
2. A suffix of s is a palindrome if and only if it equals the corresponding prefix of t.
   That is, if s[i…n-1] (where n = s.size()) is a palindrome, then it equals t[0…n-i-1].
3. To find the longest palindromic suffix of s, we can find the longest prefix of t that is also a suffix of s.

Efficient method (O(n) time using KMP):
----------------------------------------
1. Build the combined string: combined = t + '#' + s
   - The special character '#' is used to separate t and s so that no false overlaps occur.
2. Compute the prefix (failure) function for the combined string.
3. The value of the prefix function at the last position gives the length k of the longest substring 
   which is a prefix of t (and hence, a suffix of s) that matches.
4. Then, s.substr(n - k, k) is the longest palindromic suffix.

Below is the complete C++ code implementing this logic.
*/
using namespace std;
typedef int ll;

vector<int> computePrefix(const string &str) {
    int n = str.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) 
    {
        int j = pi[i - 1];
        while (j > 0 && str[i] != str[j]) 
        {
            j = pi[j - 1];
        }
        if (str[i] == str[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

void solve()
{
    string s; cin>>s;
    int n = s.size();
    string t = s;
    reverse(t.begin(), t.end());

    string combined = t + "#" + s;
    vector<int> pi = computePrefix(combined);
    int k = pi.back();
    string longestPalSuffix = s.substr(n - k, k);
    // cout<<longestPalSuffix<<nl;

    string ans = "";
    int ptr = 0;
    for(int j =n-1 - longestPalSuffix.size(); j >= 0; j--)
    {   
         ans += s[j];
    }
    // cout<<ans<<nl;
    string res = s;
    for(auto it:ans) res += it;
    cout<<res<<nl;





    


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