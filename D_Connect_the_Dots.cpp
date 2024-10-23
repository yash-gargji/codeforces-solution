#include<bits/stdc++.h>>
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
         int n,q;
         cin>>n>>q;
         disjoint_set st(n+1);
         vector<vector<int>>v(n+1,vector<int>(11,0));

         for(int i = 0;i<q;i++){
             int a,d,k;
             cin>>a>>d>>k;
             int num = 1;
             v[a][d] = max(v[a][d],k);

             while(num <= k && a + num*d <= n){

                int p = a + num*d;
                st.union_by_size(a + (num - 1)*d, a + num * d);
                int off = 1;

                for(int j = 1;j<= d;j++){
                    if(d % j != 0)
                      continue;
                    off = max(off,v[p][j]/(d/j));
                }
                v[p][d] = max(v[p][d],k - num);
                num += off;
             }
         }
        set<int>s;
        for(int i = 1;i<= n;i++){
            s.insert(st.ultimate_parent(i));
        }
        cout<<s.size()<<endl;
     }
}