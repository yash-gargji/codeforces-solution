#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
void multiply(vector<vector<long long>>&a,vector<vector<long long>>&b)
{
     int n = a.size();
     vector<vector<long long>>mul(a.size(),vector<long long >(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mul[i][j] = 0;
            for (int k = 0; k < n; k++)
                mul[i][j] += (a[i][k] * b[k][j]) % mod;
                mul[i][j] %= mod;
        }
    }
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a[0].size(); j++)
            a[i][j] = mul[i][j];
}
void pow(vector<vector<long long >>&F, int n){
   vector<vector<long long >>M = F;
    while (n) {
        if (n & 1) {
            multiply(F, M);
        }
        multiply(M, M);
        n >>= 1;
    }
}

int main(){
     int m,n;
     cin>>m>>n;

     vector<pair<int,int>>v;
     vector<int>s,l;
     vector<vector<long long int >>dp(m,vector<long long >(1,0)),mat(m,vector<long long>(m));
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
           dp[i][0] = num;
     }
    for(int i = 0;i<m;i++){
        for(int j = 0;j<m;j++){
            long long int num = v[i].first*v[j].first + v[i].second*v[j].first + v[i].first*v[j].second;
            mat[i][j] = num;
        }
    }
    if(n != 0){
       pow(mat,n-1);
    }
    if(n != 0){
        vector<vector<long long int >>cur(m,vector<long long >(1,0));

        for(int i = 0;i<m;i++){
             for(int j = 0;j<m;j++){
                 cur[i][0] += (dp[j][0]*mat[i][j])%mod;
                 cur[i][0] %= mod;
             }
        } 
      dp = cur;
    }
    long long ans = 0;

    for(int i = 0;i<m;i++){
         ans += dp[i][0];
         ans %= mod;
    }
     
    cout<<ans;
}