#include <bits/stdc++.h>
using namespace std;

class disjoint_set {
public:
    vector<int> parent, size;

    disjoint_set(int n) {
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
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

int func(vector<vector<int>>& edg, int &prev, int n, int &num){
      disjoint_set st(n + 1);
      for(int i = 0; i < edg.size(); i++){
         if(st.ultimate_parent(edg[i][1]) == st.ultimate_parent(edg[i][2]))
            continue;
         int ind = prev;
         int f = 1;
        
         while((1 << ind) <= edg[i][0]){
            if(((1 << ind) & edg[i][0]) > 0 && ind >= prev && ((1 << ind) & num) == 0) {
                f = 0;
                break;
            }
            ind++;
         }

         if(f){
            st.union_by_size(edg[i][1], edg[i][2]);
         }
         if(st.size[st.ultimate_parent(1)] == n)
            break;
     }
    return st.size[st.ultimate_parent(1)] == n;
}

int main(){
    int t;
    cin >> t;

     while(t--){
        int n, m;
        cin >> n >> m;

        vector<vector<int>> edg;
        int ma = 0;

        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            edg.push_back({w, u, v});
            ma = max(ma,(int)log2(w));
        }

        sort(edg.begin(), edg.end());
        int num = 0;
        
        for(int i = ma;i >= 0;i--){
            int temp = func(edg,i,n,num);
            if(!temp)
              num |= (1 << i);
        }

        cout<<num<<endl;
    }
}
