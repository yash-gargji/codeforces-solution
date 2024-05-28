#include<bits/stdc++.h>
using namespace std;

int timer = 1;

class disjoint_set{
    public:
    vector<int>parent,size;
     public:
    disjoint_set(int n){
          size.resize(n,1);
          for(int i = 0;i<n;i++){
            parent.push_back(i);
          }
    }
    int ultimate_parent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = ultimate_parent(parent[node]);
    }
    void union_by_size(int u,int v){
        int ulp_u = ultimate_parent(u);
        int ulp_v = ultimate_parent(v);

         if(ulp_u == ulp_v){
             return ;
         }
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
           parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
    long long  dfs(int node,vector<vector<int>>&adj,int parent,vector<int> &vis,vector<int> &tin,vector<int> &low,vector<vector<int>> &ans,vector<long long >&size){
        vis[node] = 1;
        tin[node] = timer;
        low[node] = timer;
        timer++;
        long long int sum = 0;

        for(auto it:adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
               sum +=  dfs(it,adj,node,vis,tin,low,ans,size);
                low[node] = min(low[node],low[it]);
                if(low[it] > tin[node]){
                    ans.push_back({node,it});
                }
            }
            else{
                low[node] = min(low[node],low[it]);
            }
        }
      return size[node] = 1 + sum;
    }
    void isSubsetSum(vector<int>&arr, vector<bool>&target){
        target[0] = true;
        target[arr[0]] = true;
        for(int i = 1; i<arr.size();i++){
            for(int j = target.size();j >= 0;j--){
            if(j - arr[i] >= 0)
                target[j] = target[j] | target[j - arr[i]];
            }
        }
    } 

int main(){
       int t;
       cin>>t;

       while(t--){
         long long  int n,m,c;
          cin>>n>>m>>c;

          disjoint_set *st = new disjoint_set(n+1);
          vector<vector<int>>adj(n+1),bridge,parent;
          vector<int>vis(n+1);
          vector<int>tin(n+1),low(n+1);
          vector<long long >size(n+1);
          unordered_map<int,int>mp;
          long long int  ans = 1e18;

          for(int i = 0;i<m;i++){
              int u,v;
              cin>>u>>v;
              adj[u].push_back(v);
              adj[v].push_back(u);
              st->union_by_size(u,v);
          }
           for(int i = 1 ;i<=n;i++){
              if(!vis[i]){
                 timer = 1;
                 dfs(i,adj,-1,vis,tin,low,bridge,size);
              }
           }
           for(int i = 1;i<=n;i++){
               if(st->ultimate_parent(i) == i){
                  mp[i] = st->size[i];
               }
           }
            if(mp.size() != 1){
                vector<int>arr;
                vector<bool>p(n+1);

                for(auto it:mp){
                    arr.push_back(it.second);
                }
                isSubsetSum(arr,p);

                for(int i = 1;i<n;i++){
                    if(p[i] == true){
                         long long a = i;
                         long long b = n - i;
                        ans = min(ans,a*a+b*b);
                    }
                }
            }

            for(int i = 0;i<bridge.size();i++){
                int ulp = st->ultimate_parent(bridge[i][0]);
                long long a = st->size[ulp];
                long long b = size[bridge[i][1]];
                a = a - b;
                if(mp.size() == 1){
                     ans = min(ans,a*a + b*b);
                     continue;
                }
                vector<int>arr;
                vector<bool>p(n+1,false);
                 
                for(auto it:mp){
                    if(it.first != ulp)
                      arr.push_back(it.second);
                }
                isSubsetSum(arr,p);

                for(int j = 0;j<=n;j++){
                    if(p[j] == true){ 
                       long long num1 = j + a ,num2 = n - j - st->size[ulp] + b;
                       ans  = min(ans,num1*num1 + num2*num2);
                    }
                }
            }
           if(ans == 1e18)
             cout<<"-1\n";
            else
             cout<<ans + 1ll*(mp.size() - 1)*c<<endl;
       }
} 