#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,int parent,vector<int>&vis,vector<int>&v,vector<int>adj[]){
     vis[node] = 1;

     for(auto it:adj[node]){
        if(!vis[it]){
           if(dfs(it,node,vis,v,adj))
             {
                v.push_back(node);
                return true;
             }
        }
        else if(it != parent && vis[it]){
             v.push_back(it);
            v.push_back(node);
            return true;
        }
     }
    return false;
}
void dis(int node,vector<int>&dis,vector<int> adj[]){
      dis[node] = 0;
      queue<int>q;
      q.push(node);

      while(!q.empty()){
         int k = q.front();
         q.pop();

         for(auto it:adj[k]){
             if(dis[it] == -1){
                dis[it] = dis[k] + 1;
                q.push(it);
             }
         }
      }
}

int main(){
    int t;
    cin>>t;
    while(t--){
         int n,a,b;
         cin>>n>>a>>b;
         map<int,int>m;
         vector<int> adj[n+1],v;
        vector<int>disa(n+1,-1),disb(n+1,-1),vis(n+1);
       
        for (int i = 0; i < n; i++) {
             int u, vec;
            cin >> u >> vec;
            adj[u].push_back(vec);
            adj[vec].push_back(u);
         }
          if(dfs(1,-1,vis,v,adj) == false){
            cout<<"NO\n";
            continue;
          }
         m[v[0]] = 1;
         for(int i = 1; i<v.size();i++){
             if(v[i] == v[0]){
                break;
             }

             m[v[i]] = 1;
         }
        dis(a,disa,adj);
        dis(b,disb,adj);
        int flag = 0;

        for(auto it:m){
           int node = it.first;

           if(disb[node] < disa[node]){
              flag = 1;
           }
        }
       if(flag) cout<<"YES\n";
       else cout<<"NO\n";
    }
}