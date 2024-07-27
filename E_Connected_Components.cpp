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
    int n, m;
    cin >> n >> m;
    disjoint_set ans(n+1);
    vector<unordered_map<int,int>>adj(n+1);
    vector<int>in(n+1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
        in[u]++;
        in[v]++;
    }
    int node = 1;
    for(int i = 1;i<= n;i++){
        if(in[i] < in[node]){
            node = i;
        }
    }
    for(int i = 1;i<= n;i++){
        if(adj[node].count(i) == 0){
            ans.union_by_size(i,node);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if(ans.ultimate_parent(node) == ans.ultimate_parent(i)){
             continue;
        }
        for(int j = 1;j<= n;j++){
            if(adj[i].count(j) == 0){
                ans.union_by_size(j,i);
            }
        }
    }

    multiset<int> set;
    unordered_map<int, int> mp;

    for (int i = 1; i <= n; ++i) {
        int ulp = ans.ultimate_parent(i);
        if (mp.count(ulp) == 0) {
            set.insert(ans.size[ulp]);
            mp[ulp] = 1;
        }
    }
    cout<<set.size()<<endl;
    for (auto it : set) {
        cout<<it<<" ";
    }
    cout << endl;

    return 0;
}
