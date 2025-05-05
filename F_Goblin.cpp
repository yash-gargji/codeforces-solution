#include<bits/stdc++.h>
using namespace std;
#define int long long

void dfs(int ind,int l,int r, map<vector<int>,int>&vis,vector<vector<pair<int,int>>>&v,int &count){
       count += r - l + 1;
       vis[{ind,l,r}] = 1;
       
       if(ind != 0){
          for(auto it:v[ind-1]){
             if(vis.count({ind-1,it.first,it.second}))
                continue;
             if(l >= it.first && l <= it.second)
                dfs(ind-1,it.first,it.second,vis,v,count);
             if(vis.count({ind-1,it.first,it.second}))
                continue;
             if(l <= it.first && it.first <= r)
                dfs(ind-1,it.first,it.second,vis,v,count);
          }
       }
       if(ind != v.size() - 1){
          for(auto it:v[ind+1]){
            if(vis.count({ind+1,it.first,it.second}))
               continue;
             if(l >= it.first && l <= it.second)
                dfs(ind+1,it.first,it.second,vis,v,count);
                if(vis.count({ind+1,it.first,it.second}))
                continue;
             if(l <= it.first && it.first <= r)
                dfs(ind+1,it.first,it.second,vis,v,count);
          }
       }
}

signed main(){
   int t;
   cin>>t;

   while(t--){
       int n;
       cin>>n;
       string s;
       cin>>s;

       vector<vector<pair<int,int>>>v(n);
       map<vector<int>,int>vis;

       for(int i = 0;i<s.size();i++){
            if(s[i] == '1'){
                v[i].push_back({i,i});
            }
            else{
               if(i != n-1)
                 v[i].push_back({i+1,n-1});
                if(i != 0)
                v[i].push_back({0,i-1});
            }
       }
       int ans = 0;
       
       for(int i = 0;i<n;i++){
           for(auto it:v[i]){
               if(vis.count({i,it.first,it.second}))
                 continue;
               int count = 0;
               dfs(i,it.first,it.second,vis,v,count);
               ans = max(ans,count);
           }
       }
      cout<<ans<<endl;
   }
}