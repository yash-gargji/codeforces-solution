#include<bits/stdc++.h>
using namespace std;
#define int long long

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         map<int,int>mp;
        int mod = 998244353;
        int a[n];
        vector<int>vis(n);
        int ans = 0;
        mp[0] = 1;

         int flag = 0;

         for(int i = 0;i<n;i++){
             cin>>a[i];
         }
         for(int i = 0;i<n;i++){
             int prev = (i == 0 ? 0 : a[i]);
             if(a[i] > i/2 + i % 2){
                if(i != 0 && vis[i-1] == 1){
                   flag = 1;
                   break;
                }
                dp[i] = dp[i-1];
             }
             if((i+1 == n || a[i+1])  == prev + 1){
                 mp[prev + 1] = (mp[prev + 1] + mp[prev] ) % mod;
                 mp[prev] = 2*(mp[prev]) % mod;
                 ans = (mp[prev] + mp[prev + 1]) % mod;
             }
             
         }
         
 
    }
}