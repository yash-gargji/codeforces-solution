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
         disjoint_set *st = new disjoint_set(n);
         unordered_map<int,int>m;
         vector<int>v(n),indegree(n);

         for(int i = 0;i<n;i++){
            cin>>v[i];
            v[i]--;
         }
         for(int i = 0;i<n;i++){
            indegree[v[i]]++;
            if(v[v[i]] != i)
               indegree[i]++;
            st->union_by_size(i,v[i]);
         }
          for(int i = 0;i<n;i++){
            int ulp = st->ultimate_parent(i);

            if(!m.count(ulp))
               m[ulp] = indegree[i];
            else
               m[ulp] = min(m[ulp],indegree[i]);
         }
         int count = 0;
         int flag = 0;
         for(auto it:m){
            if(it.second == 1)
              flag = 1;
             if(it.second == 2)
               count++;
         }
       cout<<count + flag<<" "<<m.size()<<endl;
    }
}