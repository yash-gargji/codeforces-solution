#include<bits/stdc++.h>
using namespace std;

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

int main(){
      int t;
      cin>>t;
      
      while(t--){
            int n;
            cin>>n;
            disjoint_set st(n);
            vector<int>arr(n);
            vector<pair<int,int>>ans;

            for(int i = 0;i<n;i++){
               cin>>arr[i];
            }
           for(int i = n-1;i >= 1;i--){
              vector<int>adj[i];

              for(int j = 0;j<n;j++){
                  adj[arr[j] % i].push_back(j);
              }
              int u = -1;
              int v = -1;
             
              for(int j = 0;j<i;j++){
                  int flag = 0;
                  
                  for(int k = 1;k<adj[j].size();k++){
                      if(st.ultimate_parent(adj[j][k]) != st.ultimate_parent(adj[j][0])){
                         st.union_by_size(adj[j][k],adj[j][0]);
                         flag = 1;
                         u = adj[j][0];
                         v = adj[j][k];
                         break;
                      }
                  }
                if(flag )
                   break;
              }
             if(u == -1){
                break;
             }
             ans.push_back({u+1,v+1});
           }
         if(st.size[st.ultimate_parent(0)] != n){
              cout<<"NO\n";
         }
         else{
            cout<<"YES\n";
            for(int i = ans.size()-1;i >= 0;i--){
                cout<<ans[i].first<<" "<<ans[i].second<<endl;
            }
         }
      }
}