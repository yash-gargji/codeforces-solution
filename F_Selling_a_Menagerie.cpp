#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>adj[], vector<int>&vis,vector<int>&v){
      v.push_back(node);
      vis[node] = 1;

      for(auto it:adj[node]){
         if(vis[it]){
            v.push_back(it);
         }
         else{
            dfs(it,adj,vis,v);
         }
      }
}
int main(){
    int t;
    cin>>t;
    
    while(t--){
          int n;
          cin>>n;
          vector<int>adj[n+1],indegree(n+1),vis(n+1) , cost(n);

          for(int i = 1;i<=n;i++){
              int num;
              cin>>num;
              indegree[num]++;
              adj[i].push_back(num);
          }
          queue<int>q;
          for(int i = 0;i<n;i++){
             cin>>cost[i];
              if(!indegree[i+1]){
                 q.push(i+1);
              }
          }
          while(!q.empty()){
              int node = q.front();
              q.pop();
              vis[node] = 1;
              cout<<node<<" ";

              for(auto it:adj[node]){
                  indegree[it]--;
                  if(indegree[it] == 0){
                     q.push(it);
                  }
              }
          }

          for(int i = 1;i<= n;i++){
              if(!vis[i]){
                vector<int>v;
                dfs(i,adj,vis,v);

                int ind = -1;
                int num = INT_MAX;

                for(int j = 0;j<v.size()-1;j++){
                    if(num > cost[v[j]-1]){
                       num = cost[v[j] - 1];
                       ind = j+1;
                    }
                }
                for(int j = ind;j<v.size()-1;j++){
                     cout<<v[j]<<" ";
                }
                for(int j = 0;j < ind;j++){
                     cout<<v[j]<<" ";
                }
              }
          }
         cout<<endl;
    }
}