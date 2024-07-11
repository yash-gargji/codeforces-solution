#include<bits/stdc++.h>
using namespace std;

int dfs(int node,vector<int>adj[],vector<int>&dp,vector<int>&in,vector<int>&vis){
       vis[node] = 1;
       int ma = 0;
      for(auto it:adj[node]){
         if(vis[it] == 0){
            int num = 0;
            num = dfs(it,adj,dp,in,vis);
            if(num >= 1 ){
                ma = max(ma,num);
            }
         }
      }
    if((ma == 0 && in[node] == 1) || ma > 0){
        dp[node] = ma;
        ma++;
    }
  return ma;
}

void dfs2(int node,vector<int>adj[],vector<int>&dp,int parent,int p_height,int &ans,int d,vector<int>&in){
     int ma1 = p_height;
     int ma2 = 0;

     for(auto it:adj[node]){
        if(it != parent){
           if(dp[it] >= ma1){
              ma2 = ma1;
              ma1 = dp[it] + 1;
           }    
           else if(dp[it] >= ma2){
              ma2 = dp[it] + 1;
           }
        }
     }
    if(ma1<= d){
        ans++;
    }
    for(auto it:adj[node]){
        if(it != parent){
           if(dp[it] + 1 != ma1){
              dfs2(it,adj,dp,node,ma1+1,ans,d,in);
           }    
           else{
              int h = 0;
              if(in[node] == 1){
                 h = 1;
              }
              if(ma2 != 0){
                 h = max(ma2+1,h);
              }
              if(p_height != 0){
                 h = max(p_height+1,h);
              }
               dfs2(it,adj,dp,node,h,ans,d,in);
           }
        }
     }
}

int main(){
    int n,m,d;
    cin>>n>>m>>d;
    vector<int>adj[n+1],in(n+1,0),dp(n+1,-1),vis(n+1,0);

     for(int i = 0;i<m;i++){
        int num;
        cin>>num;
        in[num] = 1;
    }

    for(int i = 0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1,adj,dp,in,vis);
 
    int ans = 0;
    dfs2(1,adj,dp,-1,0,ans,d,in);

    cout<<ans;
}