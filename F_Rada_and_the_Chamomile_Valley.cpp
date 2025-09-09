#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>par;
map<pair<int,int>,int>mp;
vector<bool> visited;
vector<int> tin, low,mark;
int timer;

void dfs(int v, int p,vector<int>adj[]) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v,adj);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v] && mark[v] && mark[to]){
                int ind = mp[{to,v}];
                par[to] = min(par[to],ind);
                par[v] = min(par[v],ind);
            }
        }
    }
}
int dfs2(int node,vector<int>adj[],int p){
     visited[node] = true;
     if(node == 0)
        return 1;
     for(auto it:adj[node]){
        if(it == p || visited[it])
          continue;
        mark[node] = max(mark[node],dfs2(it,adj,node));
     }
    return mark[node];
}

signed main(){
    int t;
    cin >> t;

    while(t--){
        int n,m;
        cin>>n>>m;
        map<pair<int,int>,int>temp;
        mp = temp;
        vector<int>adj[n];
        par.assign(n,INT_MAX);
        timer = 0;
        visited.assign(n, false);
        tin.assign(n, -1);
        low.assign(n, -1);
        mark.assign(n,0);
        mark[0] = 1;
        
        for(int i = 0;i<m;i++){
            int a,b;
            cin>>a>>b;
            a--;b--;
            mp[{a,b}] = i + 1;
            mp[{b,a}] = i + 1;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs2(n-1,adj,-1);
        visited.assign(n,false);
        dfs(0,-1,adj);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        
        for(int i = 0;i<n;i++){
            if(par[i] != INT_MAX)
              pq.push({0,par[i],i});
        }
        while(!pq.empty()){
            auto v = pq.top();
            pq.pop();

            for(auto it:adj[v[2]]){
                if(par[it] == INT_MAX){
                    par[it] = v[1];
                    pq.push({v[0] + 1,v[1],it});
                }
            }
        }
        int q;
        cin>>q;

        while(q--){
            int node;
            cin>>node;
            node--;
            cout<<(par[node] == INT_MAX ? -1 : par[node])<<" ";
        }
        cout<<endl;
        
    }
}
