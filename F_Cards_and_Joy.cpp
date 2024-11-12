#include<bits/stdc++.h>
using namespace std;
vector<int>joy(11);

int func(int ind,int count,vector<vector<int>>&dp,int k){
     if(ind < 0)
       return 0;
     if(dp[ind][count] != -1)
       return dp[ind][count];
     dp[ind][count] = func(ind-1,count,dp,k);

     for(int i = 1;i<= min(count,k);i++){
         dp[ind][count] = max(dp[ind][count],joy[i] + func(ind-1,count - i,dp,k));
     }
    return dp[ind][count];
}

int main(){
    int n,k;
    cin>>n>>k;
    unordered_map<int,int>m,fav;
    long long int ans = 0;   
    for(int i = 0;i<n*k;i++){
        int num;
        cin>>num;
        m[num]++;
    }
    for(int i = 0;i<n;i++){
        int num;
        cin>>num;
        fav[num]++;
    }
    for(int i = 1;i<=k;i++){
        cin>>joy[i];
    }
    for(auto it:fav){
        if(m[it.first] == 0)
          continue;
        vector<vector<int>>dp(it.second,(vector<int>(m[it.first] + 1,-1)));
        ans += func(it.second - 1,m[it.first],dp,k);
    }
    cout<<ans<<endl;
}