#include<bits/stdc++.h>
using namespace std;
#define int long long

int func(int ind, vector<map<pair<int,int>,int>>&dp,vector<int>&a,vector<int>&b,int o,int p){
      if(ind == a.size()) 
         return 0;
       if(dp[ind][{o,p}].find() != dp[ind][{o,p}].find() ){
           dp[ind][{o,p}];
       }
       vector<int>op = {o,p,a[ind]};
      sort( op.begin(),op.end()); 

      if(o + p >= a[ind]){
        dp[ind][{o,p}] = min(dp[ind][{o,p}] ,1 + func(ind,dp,a,b,o,p));
      }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n),b(n);

        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        for(int i = 0;i<n;i++){
            cin>>b[i];
        }
        vector<map<pair<int,int>,int>>dp(n);
        
        cout<<func(2,dp,a,b,max(a[0],b[0]),max(a[1],b[1]));
    }
}