#include <bits/stdc++.h>
using namespace std;
#define int long long 

#define mod 1e9 + 7

vector<int> func(int i,int j, vector<vector<int>> &dp,vector<int> &v1,vector<int>&v2,vector<vector<int>> &seq) {   
      int m = v1.size(),n = v2.size();
      if(j == n && i < m)
        return {0,1};
      if(i == m)
        return {(int)1e9,0};
      if(dp[i][j] != -1)
         return  {dp[i][j],seq[i][j]};

       int num = 1;
       auto vec = func(i+1,j,dp,v1,v2,seq);
       dp[i][j] = vec[0];
       seq[i][j] = vec[1];

      for(int ind1 = j;ind1<n;ind1++){
          int count = 0;
          int sum = 0;
           
          for(int k = ind1;k < n;k++){
              sum += v2[k];
              if(sum > v1[i])
                break;
              ind1 = k;
              count++;
              auto lop =  func(i+1,ind1+1,dp,v1,v2,seq);
              auto top =  func(i,ind1+1,dp,v1,v2,seq);
              if(ind1 + 1 == n)
               seq[i][j]--;
              if(lop[0] + num*(m - i - 1) == dp[i][j])
                seq[i][j] += lop[1];
              else if(lop[0] + num*(m - i - 1) < dp[i][j]){
                 dp[i][j] = lop[0] + num*(m - i - 1);
                 seq[i][j] = lop[1];
              }
              if(top[0] + num*(m - i - 1) == dp[i][j])
                seq[i][j] += top[1];
              else if(top[0] + num*(m - i - 1) < dp[i][j]){
                 dp[i][j] = top[0] + num*(m - i - 1);
                 seq[i][j] = top[1];
              }
          }
          if(count == 0){
             int a = (ind1 == j ? 0 : num);
             auto lop = func(i+1,ind1,dp,v1,v2,seq);
              if(lop[0] + a * (m - i - 1)  == dp[i][j])
                seq[i][j] += lop[1];
              else if(lop[0] + a * (m - i - 1)  <  dp[i][j]){
                 dp[i][j] = lop[0] + a * (m - i - 1);
                 seq[i][j] = lop[1];
              }
             break;
          }
          num++;
      }
    // cout<<i<<" "<<j<<" "<<seq[i][j]<<endl;
    return {dp[i][j],seq[i][j]};
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

        vector<vector<int>> dp(m, vector<int>(n,-1)),seq(m+1, vector<int>(n+1,0));
        auto num = func(0,0,dp,v2,v1,seq);
        if(num[0] < 1e9)
          cout<<dp[0][0]<<" "<<seq[0][0]<<endl;
        else 
         cout<<"-1\n";
    }
}
