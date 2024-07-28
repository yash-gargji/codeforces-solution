#include<bits/stdc++.h>
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

int main(){
    int n,k;
    cin>>n>>k;
    disjoint_set st(n+1);
    int ans = 0;

    for(int i = 0;i<k;i++){
        int u,v;
        cin>>u>>v;
        if(st.ultimate_parent(u) == st.ultimate_parent(v)){
            ans++;
        }
       st.union_by_size(u,v);
    }
  cout<<ans;
}