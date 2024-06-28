#include <bits/stdc++.h>
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

bool edgeComparator(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) return a[3] < b[3];
    return a[0] < b[0];
}

bool kruskals_mst(int n, vector<vector<int>>& edgelist) { 
    
    sort(edgelist.begin(), edgelist.end(), edgeComparator);
   
    disjoint_set *st = new disjoint_set(n+1);

    for (auto& edge : edgelist) { 
        
        if (st->ultimate_parent(edge[1]) != st->ultimate_parent(edge[2])) { 
            st->union_by_size(edge[1],edge[2]);
            if (edge[3] == 0) return true;
        } 
    } 
    return false;
} 

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edgelist;

    for (int i = 0; i < m; i++) {
        int u, v, num;
        cin >> u >> v >> num;
        edgelist.push_back({num, u, v, i});
    }
    if(m == n-1){
         cout<<(int)1e9;
         return 0;
    }

    int ans = 0;
    int low = 0;
    int high = 1e9;

    while (low <= high) {
        int mid = (low + high) / 2;
        for (int i = 0; i < m; i++) {
            if (edgelist[i][3] == 0) {
                edgelist[i][0] = mid;
            }
        }
        if (kruskals_mst(n, edgelist)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
