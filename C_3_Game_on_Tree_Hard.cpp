#include<bits/stdc++.h>
using namespace std;

int dfs1(int node,vector<int>adj[],vector<int>&vis,int turn,vector<int>&dp){
     vis[node] = 1;
     int flag = 0;

     for(auto it:adj[node]){
         if(!vis[it]){
           if(turn ==  dfs1(it,adj,vis,!turn,dp))
             flag = 1;
         }
     }
    if(flag)
     return dp[node] = turn;

    return dp[node] = !turn;
}

void dfs2(int node,vector<int>adj[],int parent,int init,int turn,vector<int>&ans,vector<int>&dp){
     int one = 0;
     int zero = 0;

     if(init == 1)
      one++;
     else if(init == 0)
      zero++;

      for(auto it:adj[node]){
          if(it != parent){
             if(dp[it] == 1)
               one++;
             else 
               zero++;
          }
      }
      if(turn == 1 && one > 0)
        ans[node] = 1;
      else if(turn == 0 && zero > 0)
       ans[node] = 1;
      else 
       ans[node] = 0;

      for(auto it:adj[node]){
          if(it != parent){
             if(dp[it] == 1){
                if(turn == 1 && one > 1){
                     dfs2(it,adj,node,1,0,ans,dp);
                }
                else if(turn == 0 && zero > 0){
                     dfs2(it,adj,node,0,1,ans,dp);
                }
                else 
                  dfs2(it,adj,node,!turn,!turn,ans,dp);
             }
             else if(dp[it] == 0){
                  if(turn == 1 && one > 0){
                     dfs2(it,adj,node,1,0,ans,dp);
                }
                else if(turn == 0 && zero > 1){
                     dfs2(it,adj,node,0,1,ans,dp);
                }
                else 
                  dfs2(it,adj,node,!turn,!turn,ans,dp);
             }
          }
      }
}

int main(){
    int n,t;
    cin>>n>>t;
    vector<int>adj[n+1],vis1(n+1),ans(n+1),dp(n+1);

    for(int i = 0;i<n-1;i++){
         int u,v;
         cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
    }
    dfs1(1,adj,vis1,1,dp);
    dfs2(1,adj,-1,-1,1,ans,dp);

    for(int i = 0;i<t;i++){
          int node;
          cin>>node;
          if(ans[node] == 1)
            cout<<"Ron\n";
          else  cout<<"Hermione\n";
    }
     
}