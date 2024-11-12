#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>adj[],vector<int>&p,int parent){
   p[node] = parent;

   for(auto it:adj[node]){
      if(it != parent){
         dfs(it,adj,p,node);
      }
   }
}

int main(){
    int n;
    cin>>n;
    vector<int>adj[n+1],p(n+1);
    vector<vector<int>>(n+1,vector<int>(log2(n)+1));

    for(int i = 0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}