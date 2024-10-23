#include<bits/stdc++.h>
using namespace std;

int check(string &s,int ind){
      int num = 0;
     for(int i = ind;i<ind + 3;i++){
          if(s[i] == 'A')
            num++;
     }
    return num/2;
}

int func(int i,int j,vector<vector<int>>&dp,vector<string>&v){
    int n = dp.size();
     if((i == n && j == 0) || (i == n-1 && j == 2) || i > n)
         return -1e7;
      if(i == n)
        return 0;
      if(dp[i][j] != INT_MIN)
         return dp[i][j];
      if(j == 2){
         int num = (v[0][i] == 'A' ? 1 : 0 ) + (v[0][i+1] == 'A' ? 1 : 0 )  + (v[1][i+1] == 'A' ? 1 : 0 );
         num = num / 2;
         dp[i][j] = max(dp[i][j],num + func(i+2,1,dp,v));
      }
      else if(j == 0){
          int num = (v[1][i-1] == 'A' ? 1 : 0 ) + (v[1][i] == 'A' ? 1 : 0 )  + (v[0][i] == 'A' ? 1 : 0 );
          num = num / 2;
          dp[i][j] = max(dp[i][j],num + func(i+1,1,dp,v));
      }
      else{
         int num = (v[0][i] == 'A' ? 1 : 0 ) + (v[0][i+1] == 'A' ? 1 : 0 )  + (v[1][i] == 'A' ? 1 : 0 );
         num = num / 2;
         dp[i][j] = max(dp[i][j],num + func(i+2,0,dp,v));
         num = (v[1][i] == 'A' ? 1 : 0 ) + (v[1][i+1] == 'A' ? 1 : 0 )  + (v[0][i] == 'A' ? 1 : 0 );
         num = num / 2;
         dp[i][j] = max(dp[i][j],num + func(i+1,2,dp,v));
      }
      if(j == 0 && i + 3 <= n){
        dp[i][j] = max(dp[i][j],check(v[0],i) + check(v[1],i-1)+func(i+3,j,dp,v));
      }
      else if(j == 1 && i + 3 <= n){
         dp[i][j] = max(dp[i][j],check(v[0],i) + check(v[1],i)+func(i+3,j,dp,v));
      }
      else if(i + 3 < n && j == 2){
          dp[i][j] = max(dp[i][j],check(v[0],i) + check(v[1],i+1)+func(i+3,j,dp,v));
      }
      return dp[i][j];
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<string>v(2);
        cin>>v[0]>>v[1];
        vector<vector<int>>dp(n,vector<int>(3,INT_MIN));

        cout<<func(0,1,dp,v)<<endl;
    }
}
