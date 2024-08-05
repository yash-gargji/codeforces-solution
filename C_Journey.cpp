#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else 
#define debug(x...) 42
#endif
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed << setprecision(7);
#define endl "\n" 
#define no cout << "NO \n";
#define yes cout << "YES \n";
#define int long long 
#define PI 3.1415926535897932384626433832795
const int inf = 1e9 ,INF = 1e18 ,mod1 = 998244353 ,mod = 1000000007; 

int32_t main() {
    fastio;
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) { 
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n == 1) {
        std::cout << 1 << endl;
        return 0;
    }

    queue<int> q;
    q.push(1);
    vector<int> vis(n + 1, -1);
    vis[1] = 0;
    int count = 0;
    double sum = 0; 

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        bool isLeaf = true;
        for (auto it : adj[curr]) {
            if (vis[it] == -1) {
                q.push(it);
                vis[it] = vis[curr] + 1;
                isLeaf = false;
            }
        }
        if (isLeaf) {
            count++;
            sum += vis[curr];
        }
    }
    std::cout << sum / count << endl;  
    return 0;
}
