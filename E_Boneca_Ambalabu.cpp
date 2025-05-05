#include<bits/stdc++.h>
using namespace std;
#define int long long

int func(int ind,vector<int>&pre,int num,int n,vector<vector<int>>&dp){
      if(ind == 30)
        return 0;
      if(dp[ind][num] != -1)
         return dp[ind][num];
        int t = 0;
      if(num + (1 << ind) <= n){
          t = max(t,(1 << ind)*(n - pre[ind]) + func(ind + 1,pre,num+(1 << ind),n,dp));
      }
      t = max(t,(1 << ind)*(pre[ind]) + func(ind + 1,pre,num,n,dp));

      return dp[ind][num] = t;
}



signed main(){
    int t;
    cin>>t;

    while(t--){
         int n;
         cin>>n;

         vector<int>arr(n),pre(30);

         for(int i = 0;i<n;i++){
             cin>>arr[i];
             int ind = 0;
             while((1 << ind) <= arr[i]){
                 if((arr[i] & (1 << ind)))
                   pre[ind]++;
                 ind++;
             }
         }
         
         vector<vector<int>>dp(30,vector<int>(n+1,-1));
         cout<<func(0,pre,0,n,dp)<<endl;
    }
}