#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>adj[],vector<pair<long long,long long>>&dp,int arr[],int c,int par){
    
    for(auto it:adj[node]){
         if(par == it)
           continue;
        dfs(it,adj,dp,arr,c,node);
    }
    long long a = arr[node];
    long long b = 0;

    for(auto it:adj[node]){
         if(it == par)
           continue;
        b += max(dp[it].first,dp[it].second);
        a += max(dp[it].second,dp[it].first - 2 * c);
    }
   dp[node].first = a;
   dp[node].second = b;
}


int main(){
    int t;
    cin>>t;

    while(t--){
        int n,c;
        cin>>n>>c;
        int arr[n];
        vector<int>adj[n];
        vector<pair<long long,long long>>dp(n);

        for(int i = 0;i<n;i++){
           cin>>arr[i];
        }
        for(int i = 0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,adj,dp,arr,c,-1);
        cout<<max(dp[0].first,dp[0].second)<<endl;
    }
}