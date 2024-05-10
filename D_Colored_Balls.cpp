#include<bits/stdc++.h>
using namespace std;

int main(){

       long long  int n;
        cin>>n;
        int mod = 998244353; 
        vector<int>v(n+1);

        for(int i = 1;i<=n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());  
        vector<vector<int>>dp(n+1,vector<int>(5009,0));
            dp[0][0] = 1;

        for(int i = 1;i<=n;i++){
                for(int j = 5000; j >=0;j--){
                       dp[i][j]  = dp[i-1][j]%mod;
                    if(j + v[i] > 5000){
                        continue;
                    }
                    dp[i][j + v[i]] += dp[i-1][j];
                    dp[i][j+v[i]]  = dp[i][j+v[i]]%mod;
                }
        }
     long long  int ans = 0;

        for(int i = 1;i<=n;i++){
            for(int j = 1; j<=5000;j++){
                if(v[i] >= j - v[i]){
                    ans += (1ll*(dp[i][j] - dp[i-1][j])*v[i])%mod;
                    ans = ans%mod;
                }   
                else{
                   ans += (1ll*(dp[i][j] - dp[i-1][j])*((j+1)/2))%mod;
                    ans = ans%mod;
                }
            }
        }
    cout<<ans<<endl;
}  