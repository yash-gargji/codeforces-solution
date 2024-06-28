#include <bits/stdc++.h>
using namespace std;

int dfs1(int node, vector<int> adj[], vector<int>& vis, vector<int>& dp) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dp[node] = max(dp[node], dfs1(it, adj, vis, dp));
        }
    }
    return 1 + dp[node];
}

void dfs2(int node, vector<int> adj[], int parent, vector<int>& dp, int h, int num, long long int k, long long int c, long long &ans) {
    int pop = max(dp[node], h);
    ans = max(ans, k * pop - num * c);

    for (auto it : adj[node]) {
        if (it != parent) {
            int ma = h+1; 
            int l = 0;
            int f = 0;
            if(dp[node] != 1 + dp[it]){
                ma = max(ma,dp[node] + 1);
            }
            else{
                 for (auto itr : adj[node]) {
                    if (it != itr && itr != parent) {
                        f = 1;
                        ma = max(ma,dp[itr] + 2);
                    }
                 }
            }
            dfs2(it, adj, node, dp, ma, num + 1, k, c, ans);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, k, c;
        cin >> n >> k >> c;

        vector<int> adj[n + 1], vis(n + 1, 0), dp(n + 1, 0);

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs1(1, adj, vis, dp);

        long long int ans = LLONG_MIN;
        dfs2(1, adj, -1, dp, 0, 0, k, c, ans);

        cout << ans << endl;
    }

    return 0;
}
