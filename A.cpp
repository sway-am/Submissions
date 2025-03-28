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

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Function to compute the prefix function (KMP algorithm)
vector<int> computePrefix(const string &str) {
    int n = str.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && str[i] != str[j]) {
            j = pi[j - 1];
        }
        if (str[i] == str[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    int n = s.size();
    
    // Create the reverse of s.
    string t = s;
    reverse(t.begin(), t.end());
    
    // Build the combined string: t + '#' + s
    string combined = t + "#" + s;
    
    // Compute the prefix function for the combined string.
    vector<int> pi = computePrefix(combined);
    
    // The last value of pi gives the length of the longest prefix of t that is also a suffix of s.
    int k = pi.back();
    
    // The longest palindromic suffix is the last k characters of s.
    string longestPalSuffix = s.substr(n - k, k);
    
    cout << longestPalSuffix << "\n";
    return 0;
}
