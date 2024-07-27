#include <bits/stdc++.h>
using namespace std;

class disjoint_set {
public:
    vector<int> parent, size;
    disjoint_set(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }
    int ultimate_parent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = ultimate_parent(parent[node]);
    }
    void union_by_size(int u, int v) {
        int ulp_u = ultimate_parent(u);
        int ulp_v = ultimate_parent(v);
        if (ulp_u == ulp_v) {
            return;
        }
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>>v;
    disjoint_set *st = new disjoint_set(n+1);
    int ans = 1;

    for(int i = 0;i<n;i++){
         int l,r;
         cin>>l>>r;
         v.push_back({l,r,i});
    }
    sort(v.begin(),v.end());
     vector<pair<int,int>>egdes;
    
    for(int i = 0;i<n;i++){
       for(int j = i+1;j<n;j++){
          if(v[j][0] > v[i][1]){
             break;
          }
          if(v[j][1] < v[i][1]){
             continue;
          }
          egdes.push_back({v[i][2],v[j][2]});
       }
      if(!egdes.size() >= n)
          break;
    } 
    if(egdes.size() != n-1){
         cout<<"NO";
         return 0;
    }
    for(int i = 0;i<egdes.size();i++){
        int u = egdes[i].first;
        int v = egdes[i].second;
        if(st->ultimate_parent(u) == st->ultimate_parent(v)){
            ans = 0;
           break;
        }
        st->union_by_size(u,v);
    }
   if(ans)
     cout<<"YES";
    else{
      cout<<"NO";
    }

}
