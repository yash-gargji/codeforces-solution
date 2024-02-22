#include<bits/stdc++.h>
using namespace std;

int dfs(int node, string s, vector<int>& vis, vector<int> adj[], int& ans) {
    int flag = -1;
    vis[node] = 1;
    int p = 0;
    int sl = 0;
    if (s[node] == 'S') {
        sl++;
    }
    else if (s[node] == 'P') {
        p++;
    }
    for (auto it : adj[node]) {
        if (!vis[it]) {
            int k = dfs(it, s, vis, adj, ans);
            if (k == 0) sl++;
            else if (k == 1) p++;
        }
    }
    if(s[node] == 'P') ans += sl;
    else if(s[node] == 'S') ans +=p;
    else if (sl != 0 && p != 0) {
        ans += min(sl,p);
    }
    if (s[node] == 'C') {
        if (sl != 0) {
            flag = 0;
        }
        else if (sl == 0 && p != 0) {
            flag = 1;
        }
    }
    else if (s[node] == 'S') flag = 0;
    else if(s[node] == 'P') flag = 1;
    else flag = 1;
    return flag;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> vis(n, 0);
        vector<int> adj[n];
        int ans = 0;

        for (int i = 1; i < n; i++) {
            int num;
            cin >> num;
            adj[i].push_back(num - 1);
            adj[num - 1].push_back(i);
        }
        string s;
        cin >> s;
        int num = dfs(0, s, vis, adj, ans);
        cout<<ans<<endl;
    }
    return 0;
}
