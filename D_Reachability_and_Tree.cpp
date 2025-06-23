#include<bits/stdc++.h>
using namespace std;
#define int long long

void func(int node,vector<int>adj[],vector<int>&vis,vector<int>&dir,vector<pair<int,int>>&ans){
        vis[node] = 1;
        
        for(auto it:adj[node]){
            if(vis[it])
              continue;
            if(dir[node]){
                ans.push_back({node,it});
            }
            else 
              ans.push_back({it,node});
            dir[it] = !dir[node];
            func(it,adj,vis,dir,ans);
        }
}

signed main(){
    int t;
    cin>>t;
    
    while(t--){
       int n;
       cin>>n;
       vector<int>adj[n+1];

       for(int i = 0;i<n-1;i++){
           int u,v;
           cin>>u>>v;
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
       vector<int>vis(n+1),dir(n+1,1);
       int fl = 0;
       vector<pair<int,int>>ans;
       pair<int,int>st;

       for(int i = 0;i<=n;i++){
           if(adj[i].size() == 2){
              fl = 1;
              vis[i] = 1;
              vis[adj[i][0]] = 1;
              vis[adj[i][1]] = 1;
              st = {adj[i][0],adj[i][1]};
              ans.push_back({i,adj[i][0]});
              ans.push_back({adj[i][1],i});
              dir[adj[i][0]] = 0;
              dir[adj[i][1]] = 1;   
              break;           
           }
       }
       if(fl == 0){
          cout<<"NO\n";
          continue;
       }
       cout<<"YES\n";
       func(st.first,adj,vis,dir,ans);
       func(st.second,adj,vis,dir,ans);
       for(int i = 0;i<n-1;i++){
           cout<<ans[i].first<<" "<<ans[i].second<<endl;
       }
    }
}