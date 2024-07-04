#include<bits/stdc++.h>
using namespace std;

long long dp[5001][5001];

long long func(int i,vector<long long>&pre,int m,int k){
       if(pre.size() - i < k*m || i + m > pre.size() || k == 0){
          return 0;
       }
       if(dp[i][k] != -1){
           return dp[i][k];
       }
       long long take = pre[i+m-1] - pre[i-1] + func(i+m,pre,m,k-1);
       long long not_take = func(i+1,pre,m,k);

       return dp[i][k] = max(take,not_take);
}

int main(){
     int n,m,k;
     cin>>n>>m>>k;
     int arr[n+1];
     vector<long long>pre(n+1); 
     memset(dp,-1,sizeof(dp));
     
     for(int i = 1;i<=n;i++){
         cin>>arr[i];
         pre[i] = arr[i] + pre[i-1];
     }
    cout<< func(1,pre,m,k);
}