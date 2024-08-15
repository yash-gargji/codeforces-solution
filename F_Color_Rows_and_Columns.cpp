#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e15;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        k += 20;
        
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            arr[i] = {a, b};
        }
        // my name  is yash garg   
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        
        for (int i = 1; i <= n; i++) {
            int row = arr[i-1].first;
            int col = arr[i-1].second;
            
            for (int curr = 1; curr <= k; curr++) {
                dp[i][curr] = dp[i-1][curr];
                int count = curr;
                int sum = 0;
                
                int r = row, c = col;
                
                while (r > 0 && c > 0 && count > 0) {
                    if (r == 1 && c == 1) {
                        count -= 2;
                        sum++;
                       if(count >= 0 && dp[i-1][count] != INF)
                          dp[i][curr] = min(dp[i][curr], sum + dp[i-1][count]);
                        break;
                    } 
                    else if (r <= c) {
                        count--;
                        sum += r;
                       if(dp[i-1][count] != INF)
                          dp[i][curr] = min(dp[i][curr], sum + dp[i-1][count]);
                        c--;
                    }
                     else {
                        sum += c;
                        count--;
                        if(dp[i-1][count] != INF)
                          dp[i][curr] = min(dp[i][curr], sum + dp[i-1][count]);
                        r--;
                    }
                }
            }
        }
         
        int num = INF;

        for(int i = k;i >= k-20;i--){
            num = min(num,dp[n][i]);
        }
        
        if (num == INF) {
            cout << -1 << endl;
        } else {
            cout << num << endl;
        }
    }
    
    return 0;
}
