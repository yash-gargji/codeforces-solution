#include<bits/stdc++.h>
using namespace std;

int dfs(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int> &child,vector<int> &depth,int level){
       vis[node] = 1;
       depth[node] = level;
       level++;

       for(auto it:adj[node]){
          if(!vis[it]){
            child[node] += dfs(it,adj,vis,child,depth,level);
          }
       }
    return child[node] + 1;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>>adj(n+1);
    vector<int>vis(n+1),child(n+1),depth(n+1),vec(n+1);

    for(int i = 0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,adj,vis,child,depth,0);

    for(int i = 1; i<= n;i++){
       vec[i] = depth[i] - child[i];
    }
    vec[0] = INT_MIN;
    sort(vec.begin(),vec.end());
    long long int sum = 0;

    for(int i = n; i>= 0;i--){
        sum += vec[i];
        k--;
        if(!k) break;
    }
    cout<<sum<<endl;
}