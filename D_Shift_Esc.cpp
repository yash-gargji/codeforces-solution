#include<bits/stdc++.h>
using namespace std;  
#define int long long

int func(int row,int col,int fact,vector<vector<vector<int>>>&dp,vector<vector<int>>&arr,int k,vector<vector<int>>&op){
    int m  = arr[0].size();
    if(row == arr.size()-1 && col == arr[0].size()-1){
        return arr[row][(col + fact)%m];
    }
    if(dp[row][col][fact] != -1){
       return dp[row][col][fact];
    }
    int num = 1e17;
    
    if(col + 1 < arr[0].size()){
       num = min(num, func(row,col+1,fact,dp,arr,k,op));
    }
    if(row + 1 < arr.size()){
          num = min(num,k*op[row][col] + func(row+1,col,op[row][col],dp,arr,k,op));
    }
  return dp[row][col][fact] = num + arr[row][(col + fact)%m];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int m,k;
        cin>>m>>k;
        
        vector<vector<int>>arr(n,vector<int>(m));
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        vector<vector<int>>op(n,vector<int>(m,0));
        
        for(int i = 0;i<n;i++){
           for(int j = 0;j<m;j++){
              cin>>arr[i][j];
           }
        }
        
        for(int i = 0;i<n-1;i++){
           for(int j = 0;j<m;j++){
              int num = 1e18;
              for(int l = 0;l<m;l++){
                if(l < j && (m - j + l-1)*k + arr[i][l] < num){
                    num = (m - j + l-1)*k + arr[i][l];
                    op[i][j] = (m - j + l-1);
                }
                else if(l >= j && (l - j)*k + arr[i][l] < num){
                    num = (l - j)*k + arr[i][l];
                    op[i][j] = (l - j);
                }
              }
           }
        }
        int num = 1e18;
        cout<<op[0][0]*k + func(0,0,op[0][0],dp,arr,k,op)<<endl;
    }
}