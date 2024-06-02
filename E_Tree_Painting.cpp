#include<bits/stdc++.h>
using namespace std;

long long dfs1(int node, vector<int> adj[], int parent, vector<long long>& sz, vector<long long>& dp) {
    

    for (auto it : adj[node]) {
        if (it != parent) {
            dp[node] += dfs1(it, adj, node, sz, dp);
            sz[node] += sz[it];
        }
    }
    return dp[node] = dp[node] + sz[node];
}

void dfs2(int node,vector<int>adj[],int parent,vector<long long >&dp,vector<long long >&sz,long long num,long long size){

    dp[node] += num + size;
    sz[node] += size;
     
     for(auto it:adj[node]){
         if(it != parent){                         
           long long k = dp[node] - dp[it] - sz[it];
           dfs2(it,adj,node,dp,sz,k,sz[node] - sz[it]);
         }
     }
}


int main(){
    int n;
    cin>>n;
    vector<int>adj[n+1];
    vector<long long >sz(n+1,1),dp(n+1);
    
    for(int i = 0;i<n-1;i++){
         int u,v;
         cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
    }
   long long a =  dfs1(1,adj,-1,sz,dp);
    dfs2(1,adj,-1,dp,sz,0,0);

    cout<<*max_element(dp.begin(),dp.end());
}