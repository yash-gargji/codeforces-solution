#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n,m;
        cin>>n>>m;
        vector<long long int>dis(n+1,1e17);
        vector<pair<long long int, long long int>> adj[n+1];
        vector<long long int>s1(n+1),s2(n+1);

        for (int i = 0; i < m; i++) {
            long long int u, v, cost;
            cin >> u >> v >> cost;
            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
         }
         for(int i = 1; i<=n;i++){
            cin>>s1[i];
            s2[i] = s1[i];
        }
        
        priority_queue< vector<long long int>, vector<vector<long long int>>, greater<vector<long long int>>> pq;
        dis[1] = 0;
        pq.push({s1[1],0,1});

        while(!pq.empty()){
        long long int node = pq.top()[2];
        long long  int dist = pq.top()[1];
        long long int slow = pq.top()[0];
        pq.pop();

        for(auto it:adj[node]){
            long long  int edgew = it.second;
            long long int adjnode= it.first;
               dis[node] = min(dis[node],dist);
            if(edgew*slow + dist < dis[adjnode] || s2[adjnode] > slow){
                s2[adjnode] = min(s2[adjnode],slow);
                dis[adjnode] = min(dis[adjnode],edgew*slow + dist);
                pq.push({min(s1[adjnode],slow),slow*edgew + dist,adjnode});
            }
        }
        }
         cout<<dis[n]<<endl;
    }
  return 0;
}