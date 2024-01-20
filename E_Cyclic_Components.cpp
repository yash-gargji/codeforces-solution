#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>adj[],int visited[],int &num,int parent,int &check){
        visited[node] = 1;
        for(auto &adjnode:adj[node]){
            if(!visited[adjnode]){
                dfs(adjnode,adj,visited,num,node,check);
            }
            else if(adjnode != parent){
                   num = 1;
            }
        }
        if(adj[node].size() != 2){
            check = 1;
        }
}

int main(){
    int n;
    cin>>n;
    vector<int>adj[n+1];
    int m;
    cin>>m;

    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int count = 0;
    int visited[n+1] = {0};
    for(int i = 1;i<=n;i++){
        int num = 0;
        int check = 0;
        if(!visited[i]){
        dfs(i,adj,visited,num,0,check);
        }
         if(!check){
            count = count+num;
         }
    }
    cout<<count;
}