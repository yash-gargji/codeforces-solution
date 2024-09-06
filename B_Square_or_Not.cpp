 #include<bits/stdc++.h>
 using namespace std;
 
 int func(int node,vector<pair<int,int>>adj[],int p,vector<int>&child){
    int num = 1;

    for(auto it : adj[node]){
        if(it.first != p){
           num += func(it.first,adj,node,child);
        }
    }
    return child[node] = num;
 }
 void dfs(int node,vector<pair<int,int>>adj[],int p,vector<int>&child
 ,long long sum,vector<int>&min_activity,int &ans){

      if(p != -1 && sum > min_activity[node-1]){
          ans += child[node];
          return ;
      }
      
    for(auto it : adj[node]){
        if(it.first != p){
           long long num = sum + it.second;
           num = max(num,1ll*it.second);
            dfs(it.first,adj,node,child,num,min_activity,ans);
        }
    }
 }
 
 int getMinServers(int n,vector<int>server_from,vector<int>server_to,vector<int>server_weight,vector<int>min_activity){
     vector<pair<int,int>>adj[n+1];
     vector<int>child(n+1);

     for(int i = 0;i<n-1;i++){
        int u = server_from[i];
        int v = server_to[i];
        int w = server_weight[i];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
     }
      int ans = 0;
     func(1,adj,-1,child);
     dfs(1,adj,-1,child,0,min_activity,ans);

     return ans;
 }

 int main(){
      int n = 5;
      vector<int>k = {1,1,3,3};
      vector<int>v = {2,3,4,5};
      vector<int>w = {-2,5,-5,-3};
      vector<int>act = {0,-10,5,-5,5};

      cout<<getMinServers(n,k,v,w,act);
 }