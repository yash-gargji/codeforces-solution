#include<bits/stdc++.h>
using namespace std;

int dfs(int node,vector<int>adj[],vector<int>&vis,int turn){
     vis[node] = 1;
     int flag = 0;

     for(auto it:adj[node]){
         if(!vis[it]){
           if(turn ==  dfs(it,adj,vis,!turn))
             flag = 1;
         }
     }
    if(flag)
     return turn;

    return !turn;
}

int main(){
    int n,t;
    cin>>n>>t;
    vector<int>adj[n+1],vis(n+1);

    for(int i = 0;i<n-1;i++){
         int u,v;
         cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
    }
    int root;
    cin>>root;
    if(dfs(root,adj,vis,1) == 1)
      cout<<"Ron";
     else 
      cout<<"Hermione";
}