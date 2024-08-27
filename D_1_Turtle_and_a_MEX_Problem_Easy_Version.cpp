#include<bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(int node,map<int,vector<int>>&m,map<int,int>&vis,long long &ans){
     ans = max(ans,1ll*node);
     vis[node] = 1;

     for(auto it:m[node]){
         if(vis.find(it) == vis.end()){
            dfs(it,m,vis,ans);
         }
     }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        map<int,vector<int>>mp;
         long long ans=  0;

        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            map<int,int>p;
            for(int j = 0;j<num;j++){
                int k;
                cin>>k;
                p[k]++;
            }
            int a,b;
            int  count = 0;
            num = 0;
            while(count < 2){
              if(p.find(num) == p.end() && count == 0){
                  a = num;
                  count++;
              }
              else if(p.find(num) == p.end() && count == 1){
                  b = num;
                  count++;
              }
              num++;
            }
            mp[a].push_back(b);
        }
       map<int,int>vis;
       for(auto it:mp){
          if(vis.find(it.first) == vis.end() ){
             dfs(it.first,mp,vis,ans);
          }
       }
      long long count = 0;
      if(ans >= m){
         count += ans*(m+1);
      }
      else{
         count += ans*(ans+1);
         count += m*(m+1)/2 - ans*(ans + 1)/2;
      }
      cout<<count<<endl;
    }
    return 0;
}