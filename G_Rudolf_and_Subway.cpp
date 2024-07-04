#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;
   
        vector<pair<int,int>>adj[n];
        vector<int>dis(n,INT_MAX);
        map<int,vector<int>>mp;

        for(int i = 0;i<m;i++){
            int u,v,c;
            cin>>u>>v>>c;
            u--;
            v--;
            adj[u].push_back({v,c});
            adj[v].push_back({u,c});
            mp[c].push_back(v);
            mp[c].push_back(u);
        }
        int b,e;
        cin>>b>>e;
        b--;
        e--;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        dis[b] =  0;
        pq.push({0,b,-1});

        while(!pq.empty()){
             auto v = pq.top();
             pq.pop();
             int node = v[1];
             int color = v[2];
             int d = v[0];

             for(auto it:adj[node]){
                int num = d;
                 if(it.second != color){
                    num++;
                 }
                 if(num < dis[it.first]){
                    pq.push({num,it.first,it.second});
                    dis[it.first] = num;
                    for(auto itr:mp[it.second]){
                        if(num < dis[itr]){
                          dis[itr] = num;
                          pq.push({num,itr,it.second});
                        }
                    }
                 }
             }
        }
      cout<<dis[e]<<endl;
    }
  return 0;
}