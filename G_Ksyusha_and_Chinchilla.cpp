#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>,int>m;

int dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&ans){
       vis[node] = 1;
       int sum = 0;

       for(auto it:adj[node]){
           if(!vis[it]){
               int num = dfs(it,adj,vis,ans);
               if(num == 3)
                 {
                     num = num - 3;
                    ans.push_back(m[{node,it}]);
                 }
                sum += num;
           }
       }
    return sum + 1;
}

int main(){
    int t;
    cin>>t;

    while(t--){
         int n;
         cin>>n;
         vector<int>vis(n+1),adj[n+1];
         vector<int>ans;

         for(int i = 0;i<n-1;i++){
             int u,v;
             cin>>u>>v;
             m[{u,v}] = (i+1);
             m[{v,u}] = (i+1);
             adj[u].push_back(v);
             adj[v].push_back(u);
         }
         int num = dfs(1,adj,vis,ans);
         if(num != 3){
              cout<<"-1\n";
              continue;
         }
         cout<<ans.size()<<endl;

         for(int i = 0;i<ans.size();i++){
            cout<<ans[i]<<" ";
         }
        cout<<endl;
    }
}