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


bool isSubsetOf(int val, int mask) {
    return (val & ~mask) == 0;
}

vector<int> buildArray(int len, int mask) {
    int allowedCount = 0;
    while (isSubsetOf(allowedCount, mask))
        ++allowedCount;
    
    vector<int> arr;
    
    if (len < allowedCount) {
        int currentOR = 0;
        for (int i = 0; i < len; ++i)
            currentOR |= i;

        if (currentOR == mask) {
            for (int i = 0; i < len; ++i)
                arr.push_back(i);
        } else {
            int partialOR = 0;
            for (int i = 0; i < len - 1; ++i)
                partialOR |= i;
            
            int adjust = mask & ~partialOR;
            for (int i = 0; i < len - 1; ++i)
                arr.push_back(i);
            arr.push_back(adjust);
        }
    } else {
        int prefixOR = 0;
        for (int i = 0; i < allowedCount; ++i)
            prefixOR |= i;

        if (prefixOR == mask) {
            for (int i = 0; i < allowedCount; ++i)
                arr.push_back(i);
            while (arr.size() < (size_t)len)
                arr.push_back(0);
        } else {
            int missing = mask & ~prefixOR;
            if (len == allowedCount) {
                int partialOR = 0;
                for (int i = 0; i < allowedCount - 1; ++i)
                    partialOR |= i;
                
                missing = mask & ~partialOR;
                for (int i = 0; i < allowedCount - 1; ++i)
                    arr.push_back(i);
                arr.push_back(missing);
            } else {
                for (int i = 0; i < allowedCount; ++i)
                    arr.push_back(i);
                arr.push_back(missing);
                while (arr.size() < (size_t)len)
                    arr.push_back(0);
            }
        }
    }
    return arr;
}

void solve() {
    int N, X;
    cin >> N >> X;
    vector<int> result = buildArray(N, X);
    for (int num : result) 
        cout << num << " ";
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
