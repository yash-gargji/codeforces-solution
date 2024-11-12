#include<bits/stdc++.h>
using namespace std;
vector<int>adj[5001],vis(5001);
vector<int>tim(5001);

void dfs1(int node,int t){
    vis[node] = 1;
    for(auto it:adj[node]){
       if(vis[it] == 0){
         dfs1(it,t);
       }
    }
}
void dfs2(int node,int t){
    vis[node] = 2;
    tim[node] = t;
    for(auto it:adj[node]){
       if(vis[it] == 0 || (vis[it] == 2 && tim[it] != t)){
         dfs2(it,t);
       }
    }
}

int main(){
    int n,m,s;
    cin>>n>>m>>s;
    int t = 0;

    for(int i = 0;i<m;i++){
        int  u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    dfs1(s,0);
    
    for(int i = 1;i<= n;i++){
        if(vis[i] == 0){
            t++;
            dfs2(i,t);
        }
    }
     set<int>st;
    for(int i =0;i<=n;i++){
         if(tim[i] != 0)
           st.insert(tim[i]);
    }
  cout<<st.size()<<endl;
}