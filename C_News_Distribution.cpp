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
/* in by rank we onlye increase the rank by 
1 when rank is equal else just simply join the small rank to the large rank */
};

int main(){
    int n,m;
    cin>>n>>m;

    disjoint_set st(n+1);

    for(int i = 0;i<m;i++){
        int num;
        cin>>num;
        vector<int> v(num);
        for(int j = 0;j<num;j++){
            cin>>v[j];
            if(j >=1){
                st.union_by_size(v[j],v[0]);
            }
        } 
    }
  for(int i = 1;i<=n;i++){
     int parent = st.ultimate_parent(i);
      cout<<st.size[parent]<<" ";
  }
}