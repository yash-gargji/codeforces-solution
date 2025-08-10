#include<bits/stdc++.h>
using namespace std;

int func(int prev, int mask, vector<int> adj[], vector<vector<int>>& dp) {
    if(dp[prev][mask] != -1)
        return dp[prev][mask];
    
    int num = 0;
    for(auto it : adj[prev]) {
        if((mask & (1 << it)) != 0)
            continue;
        int temp = mask ^ (1 << it);
        num = max(num, 1 + func(it, temp, adj, dp));
    }
    return dp[prev][mask] = num;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<string>> v(n + 1);
        vector<int> adj[n + 1];
        vector<vector<int>> dp(n + 1, vector<int>((1 << (n + 1)), -1));

        for(int i = 1; i <= n; i++) {
            string s1,s2;
            cin>>s1>>s2;
            v[i] = {s1,s2};
        }

        for(int i = 0; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == 0 || v[i][0] == v[j][0] || v[i][1] == v[j][1]) {
                    adj[i].push_back(j);
                }
            }
        }
        // cout<<adj[1].size()<<endl;

        cout << n - func(0, 1, adj, dp) << endl;
    }
}
