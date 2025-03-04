#include <bits/stdc++.h>
using namespace std;
 
const int M = 200001;
 
// Set to hold pairs: { -depth, dfs_order }
// Sorting by -depth lets us binary-search based on depth.
set<pair<long long, int>> active;
 
// Global arrays:
// depthArr: depth of each node (sum of weights from root)
// limitVal: the given "a[i]" limit for each node
long long depthArr[M], limitVal[M];
 
// visited array to mark nodes during DFS.
int visited[M];
 
// diff[] is our difference array used along the DFS order.
int diffArr[M];
 
// Adjacency list: for each node, list of (neighbor, edge_weight)
vector<pair<int, long long>> adj[M];
 
// dfs_order tracks the current position (order index) in DFS.
int dfs_order = 0;
 
// result[node] will store the computed answer for node.
int result[M];
 
// DFS function that returns the sum (number of contributions) in the subtree.
int dfs(int node) {
    visited[node] = 1;
    dfs_order++;                     // Entering a new node: increase DFS index.
    int curIndex = dfs_order;
    int subtreeSum = 0;              // Will accumulate contributions from the subtree.
    
    // Insert the current node into the set.
    active.insert({ -depthArr[node], curIndex });
    
    // Process all children (neighbors not yet visited).
    for (auto &edge : adj[node]) {
        int nxt = edge.first;
        long long w = edge.second;
        if (!visited[nxt]) {
            depthArr[nxt] = depthArr[node] + w;
            subtreeSum += dfs(nxt);
        }
    }
    
    int pos;
    // If current node's depth exceeds its limit, find the cutoff position.
    if (depthArr[node] > limitVal[node])
        pos = (*active.upper_bound({-(depthArr[node] - limitVal[node]), 1000000009})).second;
    else
        pos = 0; // No cutoff needed.
    
    subtreeSum++;         // Include the current node in the sum.
    diffArr[pos]++;       // Mark that starting at position 'pos', contribution increases.
    subtreeSum -= diffArr[curIndex]; // Remove contributions starting at current DFS index.
    result[node] = subtreeSum; // Store the computed result for this node.
    
    // Clean up: remove current node from active set and reset difference for this DFS position.
    active.erase({ -depthArr[node], curIndex });
    diffArr[curIndex] = 0;
    dfs_order--;          // Backtrack: decrease DFS index.
    
    return subtreeSum;
}
 
int main() {
    int n;
    scanf("%d", &n);
    
    // Read the limits for each node.
    for (int i = 1; i <= n; i++)
        scanf("%lld", &limitVal[i]);
    
    // Read the tree edges.
    // The tree is rooted at 1. For i = 2..n, read the parent and the weight.
    for (int i = 2; i <= n; i++) {
        int parent;
        long long w;
        scanf("%d %lld", &parent, &w);
        // Since the tree is undirected, add edge both ways.
        adj[parent].push_back({i, w});
        adj[i].push_back({parent, w});
    }
    
    dfs(1);  // Start DFS from the root.
    
    // Print the result for each node.
    // We subtract 1 because each node counted itself.
    for (int i = 1; i <= n; i++)
        printf("%d ", result[i] - 1);
    return 0;
}
