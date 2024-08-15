#include<bits/stdc++.h>
using namespace std;

double dfs(int node,vector<int>adj[],int parent,int l,double val){
    double sum = 0;
    int size = adj[node].size()-1;
    if(parent == -1)
     size++;

    for(auto it:adj[node]){
        if(it!= parent){
           sum += dfs(it,adj,node,l+1,val/size);
        }
    }
   if(adj[node].size() == 1 && adj[node][0] == parent){
      return l*val;
   }
   return sum;
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
     cout<<fixed<< setprecision(8)<<dfs(1,adj,-1,0,1.00);
}
