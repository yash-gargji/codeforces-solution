#include<bits/stdc++.h>
using namespace std;

int main(){
     int m,n;
     cin>>m>>n;

     vector<pair<int,int>>v;
     vector<int>s,l;
     vector<long long>dp(m);
     int mod = 1e9 + 7;

     for(int i = 0;i<m;i++){
         int num;
         cin>>num;
         s.push_back(num);
     }
     for(int i = 0;i<m;i++){
         int num;
         cin>>num;
         l.push_back(num);
     }

     for(int i = 0;i<m;i++){
         v.push_back({s[i],l[i]});
     }
     n = n-1;
     for(int i = 0;i<m;i++){
          long long int num = v[0].first*v[i].first + v[0].second*v[i].first + v[0].first*v[i].second;
           dp[i] = num;
     }
     while(n--){
        vector<long long>cur(m);
        for(int i = 0;i<m;i++){
            for(int j = 0;j<m;j++){
               long long int num = v[i].first*v[j].first + v[i].second*v[j].first + v[i].first*v[j].second;
               cur[j] += ((dp[i] % mod)*num)%mod;
               cur[j] %= mod;
            }
        }
      dp = cur;
     }
    long long ans = 0;
    for(int i = 0;i<m;i++){
         ans += dp[i];
         ans %= mod;
    }
    cout<<ans;
}