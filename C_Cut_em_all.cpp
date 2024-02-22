#include<bits/stdc++.h>
using namespace std;

int dfs(int node,vector<int> adj[],vector<int> &vis,int &ans){
    vis[node] = 1;
    int sum = 1;
    for(auto it:adj[node]){
        if(!vis[it]){
            sum += dfs(it,adj,vis,ans);
        }
    }
  if(sum % 2 == 0 && node != 1){
    ans++;
    return 0;
  }
  return sum;
}

int main(){
    int n;
    cin>>n;
     vector<int>adj[n+1];
     vector<int>vis(n+1);

     for(int i = 0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
     }
     if(n % 2) {
        cout<<"-1";
        return 0;
     }
    int ans = 0;
     dfs(1,adj,vis,ans);
     cout<<ans;
}