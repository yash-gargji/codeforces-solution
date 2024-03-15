#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;
   
        vector<pair<int,int>>adj[n];
        vector<int>dis(n,-1);

        for(int i = 0;i<m;i++){
            int u,v,c;
            cin>>u>>v>>c;
            u--;
            v--;
            adj[u].push_back({v,c});
            adj[v].push_back({u,c});
        }
       set<pair<int,pair<int,unordered_set<int>>>>s;
       int start,end;
       cin>>start>>end;
       start--;
       end--;
        unordered_set<int>mp;
       s.insert({0,{start,mp}});
       while(s.size()){
           auto p =*(s.begin());
           s.erase(s.begin());
           if(p.second.first == end){
             cout<<p.first<<endl;
             break;
           }
           for(auto it:adj[p.second.first]){
                int c = it.second;
                int adjnode = it.first;
                int size;
                int flag = 0;
                if(p.second.second.find(c) == p.second.second.end()){
                    size = 1 + p.second.second.size();
                    flag = 1;
                }
                else {
                    size = p.second.second.size();
                }
                if(dis[adjnode] == -1 || dis[adjnode] < size){
                    p.second.second.insert(c);
                    s.insert({size,{adjnode,p.second.second}});
                    flag++;
                }
                if(flag == 2){
                    p.second.second.erase(c);
                }
           }
       }
    }
  return 0;
}