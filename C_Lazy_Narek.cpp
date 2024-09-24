#include<bits/stdc++.h>
using namespace std;

int func(int i, int ind, unordered_map<int,vector<vector<int>>>& mp, vector<vector<int>>& dp) {
    if(i == dp.size()) {
        return -2*ind;
    }
    if(dp[i][ind] != INT_MIN) {
        return dp[i][ind];
    }
    int take = mp[i][ind][0] + func(i+1, mp[i][ind][1], mp, dp);
    int not_take = func(i+1, ind, mp, dp);
     dp[i][ind] = max({take, not_take,-2*ind});
    return dp[i][ind];

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        string s = "narek";
        vector<vector<int>> dp(n, vector<int>(5, INT_MIN));
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        unordered_map<int, vector<vector<int>>> mp;
        for(int i = 0; i < n; i++) {
            vector<vector<int>> p(5);
            mp[i] = p;
        }
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < n; j++) {
                int count = 0;
                int ind = i;
                for(int k = 0; k < m; k++) {
                    char c = v[j][k];
                    if(c != s[ind] && (c == s[0] || c == s[1] || c == s[2] || c == s[3] || c == s[4])) {
                        count--;
                    } 
                    else if(c == s[ind]) {
                        count++;
                        ind = (ind + 1) % 5;
                    }
                }
                mp[j][i].push_back(count);
                mp[j][i].push_back(ind);
            }
        }
        int num = func(0, 0, mp, dp);
        cout << num << endl;
    }
}