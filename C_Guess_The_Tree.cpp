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
void func(int l, int r,disjoint_set &st,vector<vector<int>>&adj){
       if(st.ultimate_parent(l) == st.ultimate_parent(r)){
          return ;
       }
       int num;
       cout<<"? "<<l<<" "<<r<<endl;
       cin>>num;
       if(num == l || num == r){
         adj[l].push_back(r);
         st.union_by_size(l,r);
         return ;
       }
       func(l,num,st,adj);
       func(r,num,st,adj);
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        disjoint_set st(n+1);
        vector<vector<int>>adj(n+1);
         
        for(int i = 2 ;i <= n;i++){
             func(i-1,i,st,adj);
        }
       cout<<"! ";
       for(int i = 1;i<= n;i++){
          for(auto it:adj[i]){
              cout<<i<<" "<<it<<" ";
          }
       }
      cout<<endl;
    }
}