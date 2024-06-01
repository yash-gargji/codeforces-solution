#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin>>n;
      vector<int>v(9),dp(n+1,0);
      vector<pair<int,int>>par(n+1);
      vector<int>count(9,0);

      for(int i = 0;i<9;i++){
         cin>>v[i];
      }

      for(int i = 0;i<9;i++){
          if(v[i] > n)
            continue;
         for(int j = 0;j<=n;j++){
           if(j - v[i] >= 0){
             if(dp[j] <= 1 + dp[j - v[i]]){
                 dp[j] = 1 + dp[j - v[i]];
                 par[j] = {i,v[i]};
             }
           }
         }
      }
      int amount = n;
      while(dp[amount] != 0 ){
          count[par[amount].first]++;
          amount = amount - par[amount].second;
      }
      for(int i = 8; i >= 0;i--){
          while(count[i] > 0){
             cout<<i+1;
             count[i]--;
          }
      }
     if(dp[n] == 0)
       cout<<"-1";
}