#include <bits/stdc++.h>
using namespace std;

void findCycles(int node, int parent, vector<int> adj[], vector<int>& vis, vector<int>& stack, vector<vector<int>>& allCycles) {
    vis[node] = 1;
    stack.push_back(node);

    for (auto it : adj[node]) {
        if (!vis[it]) {
            findCycles(it, node, adj, vis, stack, allCycles);
        } 
        else if (it != parent && find(stack.begin(), stack.end(), it) != stack.end()) {
            vector<int> cycle;
            auto itPos = find(stack.begin(), stack.end(), it);
            for (auto itr = itPos; itr != stack.end(); ++itr) {
                cycle.push_back(*itr);
            }
            cycle.push_back(it);
            allCycles.push_back(cycle);
        }
    }

    stack.pop_back();
}

vector<vector<int>> getAllCycles(int n, vector<int> adj[]) {
    vector<int> vis(n, 0); 
    vector<int> stack;
    vector<vector<int>> allCycles;

    for (int i = 0; i < n; i++) {  
        if (!vis[i]) {
            findCycles(i, -1, adj, vis, stack, allCycles);
        }
    }

    return allCycles;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> adj[n];
        vector<pair<int, int>> p;
        int ans = 0;

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> cycles = getAllCycles(n, adj);

        for (int i = 0; i < cycles.size(); i++) {
             int num = 0;
            map<int, int> mp;
            for (int j = 0; j < cycles[i].size(); j++) {
                int u = cycles[i][j];
                mp[u] = 1;
                if(adj[u].size() >= 4){
                   num = 1;
                }
            }
            if(!num)
              continue;
            map<int, vector<int>> a;
            for (int j = 0; j < n; j++) {  
                if (mp.find(j) == mp.end()) {
                    for (auto it : adj[j]) {
                        if (mp.find(it) != mp.end()) {
                            a[it].push_back(j);
                        }
                    }
                }
            }
            int flag = 0;
            for (auto it : a) {
                if (it.second.size() >= 2) {
                    flag = 1;
                    p.push_back({it.first, it.second[0]});
                    p.push_back({it.first, it.second[1]});
                }
            }
            if (flag) {
                for (int j = 1; j < cycles[i].size(); j++) {
                    p.push_back({cycles[i][j], cycles[i][j - 1]});
                }
                ans = 1;
                break;
            }
        }

        if (ans) {
            cout << "YES\n" << p.size() << endl;
            for (int i = 0; i < p.size(); i++) {
                cout << p[i].first + 1 << " " << p[i].second + 1 << endl;
            }
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
