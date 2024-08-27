#include<bits/stdc++.h>
using namespace std;
#define ll long long

long long dfs(long long node,map<int,map<int,int>>&m,map<int,int>&vis,map<int,pair<int,int>>&ans,long long &k,map<int,int>&freq){
     long long a = node,b = node;
     vis[node] = 1;

     for(auto it:m[node]){
         if(vis.find(it.first) == vis.end()){
             auto p = dfs(it.first,m,vis,ans,k,freq);
             if(it.second == 1 ){
                freq[it.first] += 2;
                a = max(a,p);
                b = max(b,p);
             }
             else{
                b = max(b,p);
             }
         }
         else{
             long long p = max(ans[it.first].first,ans[it.first].second);
             if(it.second == 1 ){
                a = max(a,p);
                b = max(b,p);
             }
             else{
                b = max(b,p);
             }
         }
     }
     if(freq[node] >= 2)
       k = max(k,a);
     ans[node] = {a,b};
     return max(a,b);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        map<int,map<int,int>>mp;
        map<int,int>freq;
        long long k = 0;
        
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
            k = max(k,1ll*a);
            mp[a][b] = 2;
            freq[a]++;
        }
        for(auto &it:mp){
            if(freq[it.first] >= 2)
              for(auto &itr:it.second){
                   itr.second = 1;
              }
        }
       map<int,int>vis;
       map<int,pair<int,int>>ans;
       for(auto it:mp){
          if(vis.find(it.first) == vis.end() ){
             dfs(it.first,mp,vis,ans,k,freq);
          }
       }
       long long count = 0;
       ll o = 0;
       for(auto &it:ans){
           if(it.second.second > k && it.first <= m && it.second.second != it.first){
              o++;
              count += it.second.second;
           }
       }
       if(k >= m){
           count += (m+1 - o)*k;
       }
       else{
          count += (k+1 - o)*k;
          count += m*(m+1)/2 - k*(k+1) / 2;
       }
      cout<<count<<endl;
    }
    return 0;
}