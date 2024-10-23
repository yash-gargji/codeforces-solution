#include<bits/stdc++.h>
using namespace std;
vector<int>mp1(5001),mp2(5001);
vector<vector<int>>st(5001,vector<int>(5001,0)),it(5001,vector<int>(5001,0));

int func(int ind,vector<vector<int>>&dp,vector<int>&pre,vector<int>&v,int curr){
      if(ind == v.size())
        return 0 ;
      if(dp[ind][curr] != -1)
        return dp[ind][curr];
      int take = mp1[curr+1] - st[ind][curr+1]+ func(ind + 1,dp,pre,v,curr+1);  
      int not_take = mp2[pre[v[ind]] - curr] - it[ind][pre[v[ind]] - curr] + func(ind + 1,dp,pre,v,curr); 
      return dp[ind][curr] = max(take,not_take);
}

int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int>v;
    vector<int>pre(n);    
    int prev = -1;
    int ind1 = 0;
    int ind2 = 0;
    for(int i = 0;i<n;i++){
            int num;
            cin>>num;
        if(num == 0){
            pre[i]++;
            v.push_back(i);
            ind1++;
            ind2++;
        }
        else{
            if(num < 0){
            mp2[abs(num)]++;
            it[ind2][abs(num)]++;
            }
            else {
                mp1[abs(num)]++;
                st[ind1][abs(num)]++;
            }
        }
        if(i != 0)
            pre[i] += pre[i-1];
    }
    vector<vector<int>>dp(v.size(),vector<int>(m+1,-1));

    for(int i = 1;i<m;i++){
        for(int j = 0;j<=m;j++){
            st[i][j] += st[i-1][j];
            it[i][j] += it[i-1][j];
        }
    }
    cout<<func(0,dp,pre,v,0);
}