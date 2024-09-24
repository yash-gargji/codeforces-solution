#include<bits/stdc++.h>
using namespace std;

void dijkstra(int start, vector<vector<long long>>&dis,vector<int>&h,vector<pair<int,int>>adj[]){
     dis[start][h[start]] = 0;
     priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>pq;
     pq.push({0,start,h[start]});

     while(!pq.empty()){
         auto v = pq.top();
         int node = v[1];
         int flag = max(v[2],1ll*h[node]);
         pq.pop();
         if(dis[node][v[2]] < v[0])
            continue;
         
         for(auto it: adj[node]){
             if(flag){
                long long k = min(v[0],dis[node][1])+ it.second/2;
                if(dis[it.first][1] > k){
                   pq.push({k,it.first,1});
                   dis[it.first][1] = k;
                }
             }
             else if(v[0] + it.second < dis[it.first][0]){
                    long long k = v[0] + it.second;
                   pq.push({k,it.first,0});
                   dis[it.first][0] = k;
             }
         }
     }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        int n,m,h;
        cin>>n>>m>>h;
        vector<int>horse(n);
        
        for(int i = 0;i<h;i++){
            int num;
            cin>>num;
            horse[num-1] = 1;
        }
        vector<pair<int,int>>adj[n];

        for(int i = 0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            u--;
            v--;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<vector<long long>>src(n,vector<long long>(2,1e15)),end(n,vector<long long>(2,1e15));
        dijkstra(0,src,horse,adj);
        if(src[n-1][0] == 1e15 && src[n-1][1] == 1e15){
          cout<<"-1\n";
          continue;
        }
        dijkstra(n-1,end,horse,adj);
        long long ans = 1e15;

        for(int i = 0;i<n;i++){
            ans = min({ans,max(min(src[i][0],src[i][1]),min(end[i][0],end[i][1]))});
        }
      cout<<ans<<endl;
    }
}