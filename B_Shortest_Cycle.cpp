#include<bits/stdc++.h>
using namespace std;

int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans = INT_MAX;

        for(int i = 0;i<n;i++){
               vector<int>vis(n);
                queue<int>q;
                q.push(i);
                vector<int>parent(n,-1);
                vis[i] = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto it:adj[node]){
                        if(!vis[it]){
                            vis[it] = 1;
                            q.push(it);
                            parent[it] = node;
                        }
                        else if(it != parent[node]){
                            int count = 0;
                            int num = node;
                             while(1){
                               count += 2;
                               if(num == -1 || it == -1){
                                  break;
                               }
                               if(it == num){
                                   count--;
                                   break;
                               } 
                               else if(num == parent[it]){
                                   break;
                               }
                               num = parent[num];
                               it = parent[it];
                        }
                      ans = min(ans,count);
                    }
                }
            }
        }
        return ans == INT_MAX? -1:ans;
    }

int main(){
   int n;
   cin>>n;
   vector<long long>arr;

   for(int i = 0;i<n;i++){
      long long num;
      cin>>num;
      if(num)
        arr.push_back(num);
   }
   n = arr.size();
   if(n > 128){
      cout<<"3";
      return 0;
   }
   vector<vector<int>>edge;
   for(int i = 0;i<n;i++){
      for(int j = i+1;j<n;j++){
         if(arr[i] & arr[j]){
            edge.push_back({i,j});
         }
      }
   }
  cout<<findShortestCycle(n,edge);
}