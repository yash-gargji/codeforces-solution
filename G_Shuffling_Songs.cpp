#include <bits/stdc++.h>
using namespace std;

int dfs(int mask, vector<int>& dp, map<int, vector<int>>& mp1,map<int, vector<int>>& mp2, vector<pair<int, int>>& v, vector<int>& vis) {
     if (dp[mask] != -1) {
          return dp[mask];
     }
     int k = mask;
     dp[mask] = v.size() - __builtin_popcount(mask);
     int ind = 0;
      
     while(ind < v.size()) {
          if(vis[ind] == 1 || ((1 << ind) & mask) == 0) {
               ind++;
               continue;
          }
          vis[ind] = 1;
          for(auto it : mp1[v[ind].first]) {
            k = k | (1 << it);
          }
           
          for (auto it : mp2[v[ind].second]) {
               k = k | (1 << it);
          }
          ind++;
     }
     dp[mask] = dfs(k, dp, mp1,mp2, v, vis);

     return dp[mask];
}

long long compute_hash(string s) {
    const int p = 31;
    const int m = 1e9 + 7;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        map<int, vector<int>> mp1,mp2;

        for (int i = 0; i < n; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            int hs1 = compute_hash(s1);
            int hs2 = compute_hash(s2);
            v.push_back({hs1, hs2});
            mp1[hs1].push_back(i);
            mp2[hs2].push_back(i);
        }

        vector<int> dp(1 << n, -1);
        int ans = n;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                ans = min(ans, dfs(1 << i, dp, mp1,mp2, v, vis));
            }
        }

        cout << ans << endl;
    }
}
