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
  HINT was taken from the solution

  The main challenge was to make the graph, it is not possible to make the graph
  normally since consider when when the nodes are 2, 4, 6, 8...n ie. all even numbers
  the edges will be nC2 ==> n^2 .

  therefore to tacle this we take pimenumbers and connect numbers to those primes.
  and then remove those special primes in the end when printing the final path
  
*/

using namespace std;
typedef int ll;
const int MaxN = 3e5 + 100;
vector<int> spf(MaxN, 0); 

void sieve() {
    for (int i = 2; i < MaxN; i++) {
        if (spf[i] == 0) {  
            for (int j = i; j < MaxN; j += i) {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
}

void solve() {
    ll n, src, trg;
    cin >> n;
    vector<int> v(n);
    vector<int> dis(2 * MaxN, -1);
    vector<int> par(2 * MaxN, -1);

    vin(v, n);
    cin >> src >> trg;
    src--, trg--;

    vector<vector<int>> adj(2 * MaxN);

   
    for (int i = 0; i < n; i++) {
        int num = v[i];
        unordered_set<int> prime_factors;

        while (num > 1) {
            int factor = spf[num];
            prime_factors.insert(factor);
            while (num % factor == 0) num /= factor;
        }

        for (int factor : prime_factors) {
            adj[i].push_back(factor + MaxN);
            adj[factor + MaxN].push_back(i);
        }
    }

    
    queue<int> q;
    q.push(src);
    dis[src] = 1;
    par[src] = -1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto ch : adj[curr]) {
            if (dis[ch] == -1) {
                dis[ch] = dis[curr] + 1;
                par[ch] = curr;
                q.push(ch);
            }
        }
    }

    if (dis[trg] == -1) {
        cout << -1 << nl;
        return;
    }

  
    ll node = trg;
    vector<int> path;
    while (node != -1) {
        if (node < n) {
            path.push_back(node);
        }
        node = par[node];
    }

    reverse(path.begin(), path.end());

    cout << (dis[trg] + 1) / 2 << nl;
    for (auto it : path) {
        cout << it + 1 << space;
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();  
    
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
