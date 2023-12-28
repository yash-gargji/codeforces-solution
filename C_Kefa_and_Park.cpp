#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
 
    vector<int>adj[n+1];
     vector<int>cat(n+1);

      for(int i = 1;i<=n;i++){
        int num;
        cin>>num;
           cat[i] = num;
      }

      for(int i = 0;i<n-1;i++){
          int u,v;
          cin>>u>>v;
          adj[u].push_back(v);
          adj[v].push_back(u);
      }
     
}