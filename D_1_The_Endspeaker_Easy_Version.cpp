#include <bits/stdc++.h>
using namespace std;
#define int long long 

#define mod 1e9 + 7

int func(int i,int j, vector<vector<int>> &dp,vector<int> &v1,vector<int>&v2) {   
      int m = v1.size(),n = v2.size();
      if(j == n)
        return 0;
      if(i == m)
        return 1e9;
      if(dp[i][j] != -1)
         return  dp[i][j];

       int num = 0;
       dp[i][j] = func(i+1,j,dp,v1,v2);;

      for(int ind1 = j;ind1<n;ind1++){
          int count = 0;
          int sum = 0;
           
          for(int k = ind1;k < n;k++){
              sum += v2[k];
              if(sum > v1[i])
                break;
              ind1 = k;
              count++;
          } 
          if(count == 0){
             dp[i][j] = min(dp[i][j],num * (m - i - 1) + func(i+1,ind1,dp,v1,v2));
             break;
          }
          else{
              num++;
              dp[i][j] = min(dp[i][j],num * (m - i - 1) + func(i+1,ind1+1,dp,v1,v2));
          }
      }
    return dp[i][j];
}

signed main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n,m;
        cin >> n >> m;
        vector<int> v1(n),v2(m);
        int ans = 0;
        
        for (int i = 0; i < n; i++){
            cin>>v1[i];
        }
        for (int i = 0; i < m; i++){
            cin>>v2[i];
        }

        vector<vector<int>> dp(m, vector<int>(n,-1));
        int num = func(0,0,dp,v2,v1);
        cout<<(num >= 1e9 ? -1 : num)<<endl;
    }
}
