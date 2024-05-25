#include<bits/stdc++.h>
using namespace std;
  
void dfs(int node,vector<int>&vis,int length,int &ans,vector<int>adj[]){
        vis[node] = 1;

        for(auto it:adj[node]){
          if(!vis[it]){
               dfs(it,vis,length+1,ans,adj);
          }
        }
        vis[node] = 0;
      ans = min(ans,int(vis.size() - length));
}
long long compute_hash(string s) {
    const int p = 26;
    const int m = 1e9 + 7;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

int main(){
     int t;
     cin>>t;

     while(t--){
          int n;
          cin>>n;
         
          vector<pair<long long ,long long>>v;

          for(int i = 0;i<n;i++){
                string s1;
                string s2;
                cin>>s1>>s2;
                long long hs1 = compute_hash(s1);
                long long hs2 = compute_hash(s2);
                v.push_back({hs1,hs2});
          }
          vector<int>adj[n];
          for(int i = 0;i<n;i++){
                for(int j = i+1;j<n;j++){
                     if(v[j].first == v[i].first || v[j].second == v[i].second){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                     }
                }
          }
          int ans = n;

          for(int i = 0;i<n;i++){
                vector<int>vis(n);
                dfs(i,vis,1,ans,adj);
          }

          std::cout<<ans<<endl;
     }
}