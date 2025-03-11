#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;

/*
    the perfect time is either ceil(sqrt(d)) -1 or floor(sqrt(d)) -1
    so calculate the perfect time for every node
    use dijsktra and check if we cna arive before the perfect time, if we arive before then
    we wait else no wait.
*/

void solve(){
    int n, m;
    cin >> n >> m;
    
    
    vector<vector<vector<int>>> adj(n);
    for (int i = 0; i < m; i++){
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        A--; B--;
        adj[A].push_back({B, C, D, (int)(sqrt(D)) -1});
        adj[B].push_back({A, C, D, (int)(sqrt(D)) -1});
    }
    
    
    vector<int> dis(n, 1e18);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dis[0] = 0;
    pq.push({0, 0});
    
    while(!pq.empty()){
        auto [currt, node] = pq.top();
        pq.pop();
        if(node == n - 1){
            cout << currt << nl;
            return;
        }
        
        if(dis[node] != currt)
            continue;
        
        
        for(auto &edge : adj[node]){
            int nex = edge[0];
            int c   = edge[1];
            int d   = edge[2];
            int perfec = edge[3];
            
            
            int w = max(0LL, perfec - currt);
            
            if(currt + w + d/(currt+w+1) > currt + w + 1 + d/(currt+w+2))
                w++;
            
            int arrival = currt + w + c + d/(currt+w+1);
            if(arrival < dis[nex]){
                dis[nex] = arrival;
                pq.push({arrival, nex});
            }
        }
    }
    
    
    cout << -1 << nl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
