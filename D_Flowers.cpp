#include<bits/stdc++.h>
using namespace std;

int main(){
     int t,k;
     cin>>t>>k;
     int mod = 1e9 + 7;
     vector<int>dp = {1},pre = {0};

     while(t--){
        int a,b;
        cin>>a>>b;
        int ind = dp.size();

        while(dp.size() <= b){
             int num = dp[ind - 1];
             if(ind - k >= 0){
                 num += dp[ind - k];
             }
             num = num % mod;
             dp.push_back(num);
             pre.push_back((num + pre[pre.size() - 1])%mod);
             ind++;
        }
        
        cout << (mod + pre[b] - pre[a-1])%mod << endl;

     }
}