#include<bits/stdc++.h>
using namespace std;

int dfs(int node,vector<int>adj[],vector<int>&vis,int x,int &count,int k){
    int sum = 1;
    vis[node] = 1;

    for(auto it:adj[node]){
         if(!vis[it]){
            sum += dfs(it,adj,vis,x,count,k);
         }
    }  
    if(sum >= x && node != 0 && count < k){
        count++;
        return 0;
    }
  
   return sum;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
         vector<int>adj[n];

         for(int i = 0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
         }
          int low = 1;
          int high = n;
          int ans = 1;

          while( low <= high){
            vector<int>vis(n);
               int mid = (low+high)/2;
               int count = 0;

             int num =   dfs(0,adj,vis,mid,count,k);
              if(num < mid ){
                   high = mid - 1;
                    if(count >= k){
                        ans = max(ans,num);
                    }
              }
               else if(count >= k){
                  ans = max(ans,mid);
                  low = mid +1;
               }
               else{
                 high = mid -1;
               }
          }
        cout<<ans<<endl;
    }
    return 0;
}
