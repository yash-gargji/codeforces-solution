#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<int>adj[],int parent,int &ans,int start_node,map<int,int>&m){
     int count = 0;
    for(auto it:adj[node]){
        if(it != parent && dfs(it,adj,node,ans,start_node,m)){
           count++;
        }
    }
    if(node == start_node && count >= 3){
         ans = 0;
    }
    else if(node != start_node && count >=2){
        ans = 0;
    }
    if(m[node]) count++;
    if(count)
      return true;
    return false;
}

int main(){
    int n;
    cin>>n;
     
    vector<int>adj[n+1],v(n+1);
    
    for(int i = 0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int q;
    cin>>q;
    for(int i = 0;i<q;i++){
        int k;
        cin>>k;
        v.resize(n+1,0);
        map<int,int>m;
      for(int j = 0;j<k;j++){
         int num;
         cin>>num;
         m[num] = 1;
      }
      int ans = 1;
      dfs(m.begin()->first,adj,-1,ans,m.begin()->first,m);
      if(ans) cout<<"YES\n";
      else cout<<"NO\n";
    }
}