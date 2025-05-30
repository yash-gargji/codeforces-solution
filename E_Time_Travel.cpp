#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t;
    cin>>n>>t;
    vector<int>vis(n+1,INT_MAX);
    vector<unordered_map<int,vector<int>>>adj(t+1);
    
    for(int i = 1;i<=t;i++){
        int m;
        cin>>m;
        while (m--){
            int u,v;
            cin>>u>>v;
            adj[i][u].push_back(v); 
            adj[i][v].push_back(u); 
        }
    }
    int k;
    cin>>k;
    vector<int>v(k);

    for(int i = 0;i<k;i++){
        cin>>v[i];
    }
    int ans = -1;
    vis[1] = 0;
     
    for(int i = 0;i<k;i++){
        int count = -1;
        for(int j = i;j<k;j++){
            if(v[i] == v[j])
               count++;
            else 
              break;
        }
        queue<int>q;
        auto& mp = adj[v[i]];
        for(auto it = mp.begin(); it != mp.end();it++){
            if(vis[it->first] > i + count)
                continue;
            q.push(it->first);
            vis[it->first] = i;
        }
        while(!q.empty()){
              int node = q.front();
              if(node == n)
                  break;
              q.pop();

              for(auto it:mp[node]){
                  if(vis[node] + 1 < vis[it]){
                     vis[it] = vis[node] + 1;
                     if(vis[it] <= i + count){
                        q.push(it);
                     }
                  }
              }
              adj[v[i]].erase(node);
        }
        i += count;
        if(vis[n] < INT_MAX){
           ans = vis[n];
           break;
        }
    }
    std::cout<<ans<<endl;
}