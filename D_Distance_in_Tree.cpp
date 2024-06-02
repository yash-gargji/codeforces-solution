#include <bits/stdc++.h>
using namespace std;

void dfs1(int node, vector<int> adj[], vector<vector<int>>& dp, int parent, int k) {
    for (auto it : adj[node]) {
        if (it != parent) {
            dfs1(it, adj, dp, node, k);
            for (int i = k; i > 0; i--) {
                dp[node][i] += dp[it][i - 1];
            }
        }
    }
}

void dfs2(int node, vector<int> adj[], vector<vector<int>>& dp, int parent, int k, long long& ans) {
    if (parent != -1) {
        for (int i = k; i > 0; i--) {
            dp[node][i] += dp[parent][i - 1] - (i >= 2 ? dp[node][i - 2] : 0);
        }
    }
    ans += dp[node][k];

    for (auto it : adj[node]) {
        if (it == parent)
            continue;
        dfs2(it, adj, dp, node, k, ans);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> adj[n + 1];
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i < n; i++) { 
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1; 
    }

    dfs1(1, adj, dp, -1, k);
    long long ans = 0;
    dfs2(1, adj, dp, -1, k, ans);

    cout << ans / 2 << endl;  
}
