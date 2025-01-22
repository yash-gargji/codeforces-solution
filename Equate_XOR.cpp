#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        long long ans = 0;
        int arr[n];
        vector<vector<int>>v;

        for(int i = 0;i<n;i++){
           cin>>arr[i];
        }
        for(int i = 0;i<n;i++){
            int count = 0;
            for(int j = i;j<n;j++){
               if(arr[i] == arr[j]){
                  count++;
                  i = j;
               }
            }
            v.push_back({arr[i],count});
        }
        vector<vector<long long>>dp(n,vector<long long>(2));
        dp[n-1][0] = arr[n-1];

        for(int i = n-2;i >= 0;i--){
            if(arr[i] == arr[i+1]){
               dp[i][0] = arr[i] + dp[i+1][0];
               dp[i][1] = max(dp[i+1][0],dp[i+1][1]);
            }
            else{
                dp[i][0] = arr[i] + dp[i+1][1];
                dp[i][1] = max(dp[i+1][0],dp[i+1][1]);
            }
            ans = max({ans,dp[i][0],dp[i][1]});
        }
       cout<<ans<<endl;
        
    }
} 