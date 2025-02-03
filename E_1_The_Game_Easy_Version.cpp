#include<bits/stdc++.h>
using namespace std;

int dfs1(int node,vector<int>&f,vector<int>&s,vector<int>&v,vector<int>adj[],int parent){
    int a = v[node];
    int b = v[node];
    
    for(auto it:adj[node]){
        if(it != parent){
            int num = dfs1(it,f,s,v,adj,node);
            if(num > a){
                b = a;
                a = num;
            }
            else if(num > b){
                b = num;
            }
        }
    }
    f[node] = a;
    s[node] = b;
   return a;
}
void dfs2(int node,vector<int>&f,vector<int>&s,vector<int>adj[],int parent,vector<int>&k,int num,vector<int>&v){
     if(num > v[node]){
         k[node] = 1;
     }
    for(auto it:adj[node]){
        if(it != parent){
           if(max(f[node],num) > f[it]){
               dfs2(it,f,s,adj,node,k,max(f[node],num),v);
           }
           else{
              dfs2(it,f,s,adj,node,k,max(num,s[node]),v);
           }
        }
    }
}

int main(){
    int t;
    cin>>t;

    while(t--){
       int n;
       cin>>n;
       vector<int>v(n),k(n),f(n),s(n);
       map<int,vector<int>>m;
       vector<int>adj[n];

       for(int i = 0;i<n;i++){
          cin>>v[i];
          m[v[i]].push_back(i);
       }
       for(int i = 0;i<n-1;i++){
           int u,v;
           cin>>u>>v;
           u--;
           v--;
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
       dfs1(0,f,s,v,adj,-1);
       dfs2(0,f,s,adj,-1,k,-1,v);
       int ans = 0;
       
       for(auto it = m.rbegin(); it != m.rend();it++){
          for(auto num : it->second){
              if(k[num])
                 ans = num + 1;
          }
          if(ans)
            break;
       }
       cout<<ans<<endl;
    }
}