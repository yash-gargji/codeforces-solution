#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;

      while(t--){
            long long int n,x;
            cin>>n>>x;

             int sum = 0;
            vector<pair<int,int>>p;

            for(int i = 0;i<n;i++){
                int c,h;
                cin>>c>>h;
                p.push_back({c,h});
                sum += h;
            }
            vector<long long>dp(sum+1,1e18);
            dp[0] = 0;

             for(int i = 0;i<n;i++){
                  long long int c;
                  c = p[i].first;
                  int h;  
                  h = p[i].second;

                  for(int j = sum; j >= 0;j--){
                      if(j - h >= 0 && dp[j - h] != 1e18){
                          long long amount = i * x - dp[j - h];
                          if(amount >= c){
                              dp[j] = min(dp[j],dp[j - h] + c);
                          }
                      }
                  } 
             }
            int ans = 0;
            for(int i = sum; i >= 0;i--){
                if(dp[i] != 1e18){
                   ans = i;
                   break;
                }
            }
          cout<<ans<<endl;
      }
}