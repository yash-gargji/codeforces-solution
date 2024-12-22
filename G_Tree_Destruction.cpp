#include<bits/stdc++.h>
using namespace std;

int dfs(int node,vector<int>adj[],int &ans,int parent){
     int mx1 = 0;
     int mx2 = 0;
     for(auto it:adj[node]){
         if(it != parent){
           int num =  dfs(it,adj,ans,node);
           if(num > mx1){
              mx2 = mx1;
              mx1 = num;
           }
           else if(num  > mx2)
             mx2 = num;
         }
     }
    ans = max(ans,mx1 + mx2 + (int)adj[node].size() - 2);
    ans = max(ans,mx1 + (int)adj[node].size() - 1);
    return max(mx1 + adj[node].size() - 2,adj[node].size() - 1);
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int>adj[n+1];
        int ans = 1;
        
        for(int i = 0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            ans = max({ans,(int)adj[u].size(),(int)adj[v].size()});
        }
        
        dfs(1,adj,ans,-1);
        cout<<ans<<endl;
    }
}