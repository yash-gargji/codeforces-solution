#include<bits/stdc++.h>
using namespace std;

int dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&child){
    vis[node] = 1;
    int sum = 0;

    for(auto it:adj[node]){
        if(!vis[it]){
            sum += dfs(it,adj,vis,child);
        }
    }
    child[node] = sum+1;
  return child[node];
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int ans = 0;
        vector<int>adj[n+1],vis(n+1),child(n+1),vis1(n+1);

        for(int i = 0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       int k = dfs(1,adj,vis,child);
        queue<int>q;
        q.push(1);
        vis1[1] = 1;
        while(!q.empty()){
            int size = q.size();
            int ma = 0;
            vector<int>v;
            int l = -1;
            for(int i  = 0;i<size;i++){
                int node = q.front();
                q.pop();

                for(auto it:adj[node]){
                    if(!vis1[it]){
                         if(ma < child[it]){
                            cout<<it<<endl;
                            l = it;
                            ma = child[it];
                         }
                        vis1[it] = 1;
                        v.push_back(it);
                    }
                }
            }
           ans += ma - 1;
           for(int i = 0;i<v.size();i++){
               if(v[i] != l){
                 q.push(v[i]);
               }
           }
        }
       cout<<ans<<endl;
    }
}