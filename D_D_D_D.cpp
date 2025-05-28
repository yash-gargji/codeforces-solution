#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m,l;
        cin>>n>>m>>l;
        int e = 0;
        vector<int>odd,adj[n+1];
        vector<pair<int,int>>dis(n+1,{-1,-1});

        for(int i = 0;i<l;i++){
            int num;
            cin>>num;
            e += num;
            if(num % 2)
              odd.push_back(num);
        }
        sort(odd.begin(),odd.end());
        if(odd.size() % 2 )
          e -= odd[0];
        
        for(int i = 0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<pair<int,int>>q;
        q.push({1,0});
        dis[1].first = 0;
        
        while(!q.empty()){
            int node = q.front().first;
            int d = q.front().second;
            q.pop();
            d++;

            for(auto it:adj[node]){
                if(d % 2 == 0 && dis[it].first == -1){
                   dis[it].first = d;
                   q.push({it,d});
                }
                if(d % 2 == 1 && dis[it].second == -1){
                   dis[it].second = d;
                   q.push({it,d});
                }
            }
        }
        for(int i = 1;i<= n;i++){
            int fl = 0;
            if(dis[i].first <= e && dis[i].first != -1)
              fl = 1;
            if(odd.size() > 0 && dis[i].second != -1){
               if(odd.size() % 2 && e + odd[0] >= dis[i].second)
                 fl = 1;
               else if(odd.size() % 2 == 0 && e - odd[0] >= dis[i].second)
                 fl = 1;
            }
          cout<<fl; 
        }
       cout<<endl;
    }
}