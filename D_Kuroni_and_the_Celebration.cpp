#include<bits/stdc++.h>
using namespace std;

int dfs(int node,vector<int>adj[],map<int,int>&size,map<int,int>&parent,int p){
    int sum = 0;
    parent[node] = p;
    for(auto it:adj[node]){
        if(it != p){
           sum += dfs(it,adj,size,parent,node);
        }
    }
   
   return size[node] = 1 + sum;
}

int main(){
    int n;
    cin>>n;
     vector<int>adj[n+1];
     for(int i = 0;i<n-1;i++){
         int u,v;
         cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
     }
     int root = 1;
     while(1){
         map<int,int>size,parent;
         dfs(root,adj,size,parent,-1);
         if(size[root] == 1){
             cout<<"! "<<root;
             break;
         }
         int num = 0;
         int u,v;
         for(auto it:size){
             if(parent[it.first] == -1)
               continue;
             int k = min(it.second,size[parent[it.first]] - it.second);
             if(k > num){
                u = it.first;
                v = parent[it.first];
                num = k;
             }
         }
         int node;
         cout<<"? "<<u<<" "<<v<<endl;
         cin>>node;
        if(node == u){
           adj[u].erase(find(adj[u].begin(),adj[u].end(),v));
           root = node;
        } 
        else{
           adj[v].erase(find(adj[v].begin(),adj[v].end(),u));
           root = node;
        }
     }
}
