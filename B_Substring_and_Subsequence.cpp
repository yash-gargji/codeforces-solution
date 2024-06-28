// #include<bits/stdc++.h>
// using namespace std;

// int func(int i,int j,string &a,string &b,vector<vector<int>>&dp){
//       if(i == -1){
//          return j+1;
//       }
//       if(j == -1){
//          return 0;
//       }

//       if(dp[i][j] !=-1)
//         return dp[i][j];
//       if(a[i] == b[j]){
//           return dp[i][j] = func(i-1,j-1,a,b,dp);
//       }
//       return  dp[i][j] = 1 + min()
// }

// int main(){
//      int t;
//      cin>>t;

//      while(t--){
//          string a,b;
//          cin>>a>>b;
//          vector<vector<int>>dp(a.size(),vector<int>(b.size()),-1);

//          cout<<func(a.size()-1,b.size()-1,a,b,dp)<<endl;
//      }
// }