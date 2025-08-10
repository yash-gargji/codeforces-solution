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
  
    int n,m,k;
    cin>>n>>m>>k;
    disjoint_set st(n);
    vector<vector<int>>edg;
    
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(st.ultimate_parent(u) == st.ultimate_parent(v)){
            k--;
        }
        st.union_by_size(u,v);
    }
    unordered_map<int,int>mp;
    vector<int>v;
    
    for(int i = 0;i<n;i++){
        int ulp = st.ultimate_parent(i);
        if(mp.count(ulp) == 0){
            v.push_back(st.size[ulp]);
        }
        mp[ulp] = 1;
    }
    sort(v.begin(),v.end());
    int ind = 0;

    while(k > 0){
        if(v[ind] == 1){
            ind++;
            continue;
        }
        k--;
        v[ind]--;
    }
    long long ans = 0;

    for(int i = 0;i<v.size();i++){
        ans += 1ll*v[i]*(v[i] - 1);
    }
    cout<<ans<<endl;
    
}