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
        int m1,m2;
        cin>>m1>>m2;
        disjoint_set st1(n),st2(n);
        
        vector<vector<int>>ed1,ed2;
        vector<int>adj1[n],adj2[n];

        for(int i = 0;i<m1;i++){
           int u,v;
           cin>>u>>v;
           u--;v--;
        //    st1.union_by_size(u,v);
           ed1.push_back({u,v});

        }
        for(int i = 0;i<m2;i++){
           int u,v;
           cin>>u>>v;
           u--;v--;
           st2.union_by_size(u,v);
           ed2.push_back({u,v});
        }
        int ans = 0;
        
        for(int i = 0;i<m1;i++){
            vector<vector<int>>temp;
            if(st2.ultimate_parent(ed1[i][0]) != st2.ultimate_parent(ed1[i][1])){
               ans++;
            }
            else{
                st1.union_by_size(ed1[i][0],ed1[i][1]);
            }
        }
        for(int i = 0;i<m2;i++){
            if(st1.ultimate_parent(ed2[i][0]) != st1.ultimate_parent(ed2[i][1])){
                ans++;
                st1.union_by_size(ed2[i][0],ed2[i][1]);
            }
        }
        cout<<ans<<endl;
    }
}