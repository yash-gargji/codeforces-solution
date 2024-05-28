#include<bits/stdc++.h>
using namespace std;

int timer = 1;
    long long  dfs(int node,vector<vector<int>>&adj,int parent,vector<int> &vis,vector<int> &tin,vector<int> &low,vector<vector<int>> &ans,vector<long long >&size){
        vis[node] = 1;
        tin[node] = timer;
        low[node] = timer;
        timer++;
        long long int sum = 0;

        for(auto it:adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
               sum +=  dfs(it,adj,node,vis,tin,low,ans,size);
                low[node] = min(low[node],low[it]);
                if(low[it] > tin[node]){
                    ans.push_back({node,it});
                }
            }
            else{
                low[node] = min(low[node],low[it]);
            }
        }
      return size[node] = 1 + sum;
    }

int main(){
       int t;
       cin>>t;

       while(t--){
          int n,m,c;
          cin>>n>>m>>c;
          timer = 1;
          vector<vector<int>>adj(n+1),ans;
          vector<int>vis(n+1);
          vector<int>tin(n+1),low(n+1);
          vector<long long >size(n+1);

          for(int i = 0;i<m;i++){
              int u,v;
              cin>>u>>v;
              adj[u].push_back(v);
              adj[v].push_back(u);
          }
          dfs(1,adj,-1,vis,tin,low,ans,size);
            if(ans.size() == 0){
                 cout<<"-1\n";
            }
            else{
                 long long count = 1e18;

                 for(int i = 0;i<ans.size();i++){
                     long long a = n - size[ans[i][1]];
                     long long b = size[ans[i][1]];
                     count = min(count,a*a + b*b);
                 }
                cout<<count<<endl;
            }
       }
}