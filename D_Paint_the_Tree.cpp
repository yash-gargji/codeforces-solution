#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>adj[],int parent,vector<int>&v){
    v.push_back(node);

    for(auto it:adj[node]){
        if(it != parent){
            dfs(it,adj,node,v);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>c(4,vector<int>(n+1)) ,perm = {{1,2,3} , {1,3,2} , {2,3,1} , {2,1,3},{3,1,2},{3,2,1}};
    vector<int>adj[n+1],v;
    
    for(int i = 1;i<=3;i++){
        for(int j = 1;j<=n;j++){
            cin>>c[i][j];
        }
    }
    for(int i = 0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int flag = 1;
    int node  = -1;
    
    for(int i = 1;i<=n;i++){
        if(adj[i].size() >= 3){
            flag = 0;
            break;
        }
        else if(adj[i].size() == 1){
            node = i;
        }
    }
    if(flag == 0){
        cout<<"-1";
        return 0;
    }
    dfs(node,adj,-1,v);
    long long ans = LLONG_MAX;
    

    for(int k = 0;k<6;k++){
        int ind = 0;
        long long num = 0;
        for(int i = 0;i<v.size();i++){
           num += c[perm[k][ind]][v[i]];
           ind = (ind + 1)%3;
        }
        if(num < ans){
            ans = num;
            flag = k;
        }
    }
    cout<<ans<<endl;
    int ind = 0;
    vector<int>vec(n+1);
    for(int i = 0;i<n;i++){
        vec[v[i]] =  perm[flag][ind] ;
         ind = (ind + 1)%3;
    }
    for(int i = 1;i<=n;i++){
        cout<<vec[i]<<" ";
    }
}