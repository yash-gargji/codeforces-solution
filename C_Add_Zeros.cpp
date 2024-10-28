#include <bits/stdc++.h>
using namespace std;
#define int long long 

int func(int num, int ind, map<int, vector<int>> &m, vector<int> &dp) {   
    if (dp[ind] != -1)
        return dp[ind];
        
    dp[ind] = ind;
    
    for (auto it : m[num]) {
        dp[ind] = max(dp[ind], func(num + it, it, m, dp) + ind);
    }
    return dp[ind];
}

signed main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        int ans = 0;
        map<int, vector<int>> m;
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            m[arr[i] - (n - i)].push_back(i);
        }

        vector<int> dp(n, -1);

        for (auto it : m[0]) {
            ans = max(ans, func(it, it, m, dp));
        }
        cout << ans + n<< endl;  
    }
}
