#include<bits/stdc++.h>
using namespace std;

long long dfs(int node,vector<int>&val,vector<int>adj[],int p,vector<int>&size){
    int child = 0;
    long long small = LLONG_MAX;
    int k = -1;
    long long sum = val[node];

    for(auto it:adj[node]){
        if(it != p){
            long long num = dfs(it,val,adj,node,size);
            sum += num;
            child += size[it];
            if(small > num){
               small = num;
               k = it;
            }
        }
    }
    if(child % 2){
        sum -= small;
        child -= size[k];
    }
    // cout<<sum<<endl;
    size[node] = 1 + child;
    return sum;
}

int main(){
    int n;
    cin>>n;
    vector<int>val(n+1),size(n+1);
    vector<int>adj[n+1];
    
    for(int i = 1;i<= n;i++){
       int p;
       cin>>p;
       if( p != -1){
         adj[p].push_back(i);
         adj[i].push_back(p);
       }
       cin>>val[i];
    }
    cout<<dfs(1,val,adj,-1,size);
}