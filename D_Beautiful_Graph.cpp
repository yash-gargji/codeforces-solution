#include<bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

bool dfs(int node,vector<int>adj[],vector<int>&color,int &a,int k,int &sz){
    sz++;
    color[node] = k;
    if(!k)
      a++;
      
      for(auto it:adj[node]){
          if(color[it] == -1){
              if(dfs(it,adj,color,a,!k,sz) == false)
                return false;
          }
          else if(color[it] == color[node]){
            return false;
          }
      }
    return true;
}

int main(){
     int t;
     cin>>t;

     while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>adj[n+1],color(n+1,-1);
        int mod = 998244353;

        for(int i = 0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long ans = 1;

        for(int i = 1;i<= n;i++){
             if(color[i] == -1){
                int sz = 0;
                 int a = 0;
                if(dfs(i,adj,color,a,0,sz) == false){
                   ans = 0;
                   break;
                }
                long long num = (binpow(2,a,mod) + binpow(2,sz - a,mod)) % mod;
                ans = ans*num % mod;
             }
        }

        cout<<ans<<endl;
     } 
}