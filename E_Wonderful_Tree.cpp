#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define PQ priority_queue<pair<ll,ll>>
vector<ll> v; 
vector<vector<ll>> adj; 

//  void bfs(int node,ll h,vector<ll>&sum,ll parent,vector<ll>&height,ll &ans){
//        queue<vector<ll>>q;
//        q.push({node,0,parent}); 

//        while(!q.empty()){
//             auto n = q.front()[0];
//             ll level = q.front()[1];
//             ll p = q.front()[2];
//             q.pop();

//             if(sum[node] - v[node] >=  0 || level > h){
//                  break;
//             }
//             if(n != node && height[n] != 0 && sum[n] > v[n]){
//                 ll num = min(v[node] - sum[node],sum[n] - v[n]);
//                 v[n] += num;
//                 ans += level*num;
//                 sum[node] += num;
//             }

//             for(auto it:adj[n]){
//                  if(it != parent){
//                     q.push({it,level+1,n});
//                  }
//             }
//        }
//  }

void dfs(int node, int parent, vector<ll>& sum, vector<ll>& height, ll &ans, map<pair<ll,ll>,ll>&m, int depth, vector<vector<ll>>& anc) {
    ll num = 0;
    ll h = LLONG_MAX;

    for (auto it : adj[node]) {
        if (it != parent) {
            dfs(it, node, sum, height, ans, m, depth+1, anc);
            num += v[it];  
            h = min(h, height[it] + 1);
        }
    }
    height[node] = h == LLONG_MAX ? 0 : h;
    sum[node] = num;

    if (h != 0 && v[node] > num) {
        ll req = (v[node] - sum[node]);
        for (auto it = m.begin(); it != m.end() && req > 0; ) {
            if (it->first.first - depth >= height[node] || req == 0) {
               break;
            }
            if (anc[node][it->first.second] == 0) {
                ++it;
                continue;
            }
            if (req >= it->second) {
                req -= it->second;
                ans += (it->first.first - depth) * it->second;
                it = m.erase(it);
            } else {
                ans += (it->first.first - depth) * req;
                it->second -= req;
                req = 0;
            }
        }
        ans += height[node] * req;
        sum[node] = v[node];
    } else if (v[node] < num) {
        m[{depth, node}] = num - v[node];
    }
}

void dfs2(int node, int parent, vector<vector<ll>>& anc) {
    for (auto it : adj[node]) {
        if (it != parent) {
            dfs2(it, node, anc);
            anc[node][it] = 1;
            for (int i = 1; i < anc.size(); ++i) {
                anc[node][i] = anc[node][i] | anc[it][i];
            }
        }
    }
    anc[node][node] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<ll> sum(n + 1), height(n + 1, LLONG_MAX);
        map<pair<ll, ll>, ll> m;
        vector<vector<ll>> anc(n + 1, vector<ll>(n + 1, 0));
        v.resize(n + 1);
        adj.assign(n + 1, vector<ll>());

        for (int i = 1; i <= n; ++i) {
            cin >> v[i];
        }
        for (int i = 2; i <= n; ++i) {
            ll num;
            cin >> num;
            adj[num].push_back(i);
            adj[i].push_back(num);
        }

        dfs2(1, -1, anc);
        ll ans = 0;
        dfs(1, -1, sum, height, ans, m, 0, anc);

        cout << ans << endl;
    }
    return 0;
}
