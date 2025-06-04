#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> adj[k + 1];
        vector<long long> dp(n, 1e18);

        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            adj[num].push_back(i);
        }
        long long ans = 1e18;

        for (int i = k; i >= 0; i--){
            for (auto it : adj[i]){
                if (i == k)
                {
                    dp[it] = 0;
                    continue;
                }
                auto itr = upper_bound(adj[i + 1].begin(), adj[i + 1].end(), it) - adj[i + 1].begin();
                if (itr != adj[i + 1].size())
                {
                    dp[it] = min(dp[it], abs(adj[i + 1][itr] - it) + dp[adj[i + 1][itr]]);
                }
                itr--;
                if (itr > -1)
                {
                    dp[it] = min(dp[it], abs(adj[i + 1][itr] - it) + dp[adj[i + 1][itr]]);
                }
            }
        }
        for (auto it : adj[1])
        {
            ans = min(ans, dp[it]);
        }
        for (int i = 0; i < n; i++)
        {
            auto itr = lower_bound(adj[1].begin(), adj[1].end(), i) - adj[1].begin();
            long long num = 1e18;
            if (itr != adj[1].size())
            {
                num = abs(adj[1][itr] - i) + dp[adj[1][itr]];
            }
            itr--;
            if (itr > -1)
            {
                num = min(num, abs(adj[1][itr] - i) + dp[adj[1][itr]]);
            }
            cout<<num<<" ";
        }
        cout << endl;
    }
}