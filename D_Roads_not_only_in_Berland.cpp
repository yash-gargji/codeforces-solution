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
    int n;
    cin>>n;
     vector<vector<int>>edge;
     disjoint_set *st = new disjoint_set(n);

    vector<pair<int,int>>cyclic_edge;

    for(int i = 0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        edge.push_back({u-1,v-1});
        int ulp_u = st->ultimate_parent(u-1);
        int ulp_v = st->ultimate_parent(v-1);
        if(ulp_u == ulp_v){
           cyclic_edge.push_back({u,v});
        }
        st->union_by_size(edge[i][0],edge[i][1]);  
    }
    queue<int>q;

    for(int i = 0;i<n;i++){
        if(i == st->ultimate_parent(i))
          q.push(i+1);
    }
    int k = q.front();
    q.pop();
    cout<<q.size()<<endl;
    
    for(int i = 0;i<cyclic_edge.size();i++){
        auto p = cyclic_edge[i];
        cout<<p.first<<" "<<p.second<<" "<<k<<" "<<q.front()<<endl;
        q.pop(); 
    }
}