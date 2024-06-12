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
           int n,m;
           cin>>n>>m;
           vector<vector<char>>mat(n,vector<char>(m));
           disjoint_set *st = new disjoint_set(n*m); 

           for(int i = 0;i<n;i++){
              for(int j = 0;j<m;j++){
                  cin>>mat[i][j];
              }
           } 
           int delrow[4] = {-1,0,1,0};
           int delcol[4] = {0,-1,0,1};
            for(int i = 0;i<n;i++){
              for(int j = 0;j<m;j++){
                 if(mat[i][j] == '#')
                    for(int k = 0;k<4;k++){
                        int nrow = i + delrow[k];
                        int ncol = j + delcol[k];
                        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == '#'){
                              st->union_by_size(i*m + j,nrow*m + ncol);
                        }
                    }
              }
           }
           int ans = 0;

           for(int i = 0;i<n;i++){
               set<int>s;
               int sum = 0;

              for(int j = 0;j<m;j++){
                int ulp =  st->ultimate_parent(i*m + j);
                 if(s.find(ulp) == s.end()){
                    sum += st->size[ulp];
                    s.insert(ulp);
                }
                for(int k = 0;k<4;k++){
                    int nrow = i + delrow[k];
                    int ncol = j + delcol[k];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == '#'){
                       int ulp =  st->ultimate_parent(nrow*m + ncol);
                       if(s.find(ulp) == s.end()){
                            sum += st->size[ulp];
                            s.insert(ulp);
                       }
                    }
                }
              }
              ans = max(ans,sum);
               
           } 

           for(int i = 0;i<m;i++){
               set<int>s;
               int sum = 0;

              for(int j = 0;j<n;j++){
                int ulp =  st->ultimate_parent(j*m + i);
                if(s.find(ulp) == s.end()){
                    sum += st->size[ulp];
                    s.insert(ulp);
                }
                for(int k = 0;k<4;k++){
                    int nrow = j + delrow[k];
                    int ncol = i + delcol[k];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == '#'){
                       int ulp =  st->ultimate_parent(nrow*m + ncol);
                       if(s.find(ulp) == s.end()){
                            sum += st->size[ulp];
                            s.insert(ulp);
                       }
                    }
                }
              }
              ans = max(ans,sum);
               
           }
          cout<<ans<<endl; 
       }
}