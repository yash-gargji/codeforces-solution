#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int ma = 0;
    
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        ma = max(ma,arr[i]);
    }
    ma = (1 << ((int)log2(ma) + 1)) - 1;
    vector<int>dp(ma+1,-1);

    for(int i = 0;i<n;i++){
        dp[arr[i]] = arr[i];
    }

    for(int i = 0;i<=log2(ma);i++){
        for(int j = 0;j<= ma;j++){
            if((1 << i) & j)
              dp[j] = max(dp[j],dp[j ^ (1 << i)]);
        }
    }
    for(int i = 0;i<n;i++){
        cout<<dp[arr[i] ^ ma]<<" ";
    }


}