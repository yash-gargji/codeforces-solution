#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;
        int t0,t1,t2;
        cin>>t0>>t1>>t2;
        vector<vector<int>>adj[n+1];

        for(int i = 0;i<m;i++){
           int u,v,l0,l1;
           cin>>u>>v>>l0>>l1;
           adj[u].push_back({v,l0,l1});
           adj[v].push_back({u,l0,l1});
        }
        int ans = -1;
        int low = 0;
        int high = t0;
        
        while(low <= high){
           int mid = (low + high)/2;
           vector<long long>dis(n+1,1e18);
           priority_queue<pair<long long,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
           pq.push({mid,1});
           dis[1] = mid;

           while(!pq.empty()){
              int node = pq.top().second;
              long long time = pq.top().first;
              pq.pop();
              for(auto it:adj[node]){
                  long long num = time + it[2];
                  if(time >= t2){
                     num = min(num,time + it[1]);
                  }
                  else if(time <= t1){
                    if(time + it[1] <= t1){
                        num = min(num,time + it[1]);
                    }
                    else{
                       num = min(num,1ll*t2 + it[1]);
                    }
                  }
                 if(num < dis[it[0]]){
                    dis[it[0]] = num;
                    pq.push({num,it[0]});
                 } 
              }
           }
          if(dis[n] <= t0){
              ans = mid;
              low = mid + 1;
          }
          else{
            high = mid -1 ;
          }
        }
      cout<<ans<<endl;
    }
}