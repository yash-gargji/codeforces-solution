#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main() {
    vector<vector<int>> dp(64, vector<int>(64, 1e18)),suff(64,vector<int>(64));
    dp[0][0] = 0;
    
    for(int i = 1;i<= 42;i++){
        vector<vector<int>>curr = dp;
        for(int j = 0;j<= 63;j++){
            for(int k = 0;k <= 63;k++){
                 if(k + i <= 63 && dp[j][k] != 1e18){
                    curr[j][k+i] = min(curr[j][k+i],(1ll << i) + dp[j][k]);
                 }
                 if(j + i <= 63 && dp[j][k] != 1e18){
                    curr[j+i][k] = min(curr[j+i][k],(1ll << i) + dp[j][k]);
                 }
            }
        }
        dp = curr;
    }
    for(int j = 0;j<= 63;j++){
        for(int k = 63;k >= 0;k--){
            suff[j][k] = dp[j][k];
            if(k != 63){
                suff[j][k] = min(suff[j][k],suff[j][k+1]);
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;

        if(x == y){
            cout<<"0\n";
            continue;
        }

        if(x > y)
          swap(x,y);
        int pos=(int)log2(y);
        if(x != 0)
          pos -= (int)log2(x);

        int ind = 0;
        int ans = 1e18;

        while(ind + pos < 64){
             if((x >> ind) == 0 ){
                int k = log2(y)+1;
                ans = min(ans,suff[ind][k]);
             }
             else if((x >> ind) == (y >> (ind + pos))){
                 ans = min(ans,dp[ind][ind+pos]);
             }
             ind++;
        }
        cout<<ans<<endl;
    }
}
