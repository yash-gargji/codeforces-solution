#include<bits/stdc++.h>
using namespace std;

 void dfs(int node ,vector<int> adj[],vector<int>&cat,vector<int>&vis,int &ans,int count,int k){
       int nx_count = 0;
          if(cat[node] == 1 || count > k){
              nx_count = count + 1;
          }
          vis[node] = 1;

        if(adj[node].size() == 1 && vis[adj[node][0]] == 1)  {
            if(nx_count <= k){
                ans ++;
            }
        } 
        for(auto &adjnode : adj[node]){
            if(!vis[adjnode]){
                dfs(adjnode,adj,cat,vis,ans,nx_count,k);
            }
        }
 }

int main(){
    int n,k;
    cin>>n>>k;
 
    vector<int>adj[n+1];
     vector<int>cat(n+1,0);
     vector<int>vis(n+1,0);

      for(int i = 1;i<=n;i++){
        int num;
        cin>>num;
        cat[i] = num;
      }

      for(int i = 0;i<n-1;i++){
          int u,v;
          cin>>u>>v;
          adj[u].push_back(v);
          adj[v].push_back(u);
      }
     int ans = 0;
     dfs(1,adj,cat,vis,ans,0,k);
     cout<<ans;
}