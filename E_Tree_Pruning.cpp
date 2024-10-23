#include<bits/stdc++.h>
using namespace std;

int dfs(int node, vector<int> adj[], vector<int>& d, vector<int>& h, vector<int>& child, vector<int>& par, int depth, int p) {
    d[node] = depth;
    par[node] = p;
    
    for (auto it : adj[node]) {
        if (it != p) {
            h[node] = max(h[node], dfs(it, adj, d, h, child, par, depth + 1, node));
            child[node] += child[it] + 1;
        }
    }
    return h[node] + 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> adj[n], d(n), h(n, 0), child(n, 0), par(n, -1);
        map<int, vector<int>> m;
        vector<int>size(n);

        for(int i = 0;i<n;i++){
            size[i] = adj[i].size();
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, adj, d, h, child, par, 1, -1);

        map<int, int> tc;
        int k = 0;
        for (int i = 0; i < n; i++) {
            k = max(k,d[i]);
            tc[d[i]] += child[i];
            if (par[i] != -1 && adj[i].size() == 1)
                m[d[i]].push_back(i);
        }
        int ans = INT_MAX;
        int curr_sum = 0;

        for(int i = 1; i <= h[0] + 1; i++){
            int num = curr_sum + tc[i];
            int count = 0;
            for (auto it : m[i-1]) {
                int node = it;
                while(node != -1 && d[node] + h[node] <  i) {
                    count++;
                    node = par[node];
                    if(node != -1 && size[node] > 1){
                        size[node]--;
                        break;
                    }
                }
            }
            num += count;
            curr_sum += count;
            ans = min(ans, num);
        }

        cout <<ans<< endl;
    }
    return 0;
}
