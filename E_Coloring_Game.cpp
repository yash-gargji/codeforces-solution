#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], int c, vector<int> &vis){
    vis[node] = c;

    int ac = c == 1 ? 2 : 1;
    for (auto it : adj[node]){
        if(vis[it]){
            if(vis[it] == c){
                return false;
            }
        } 
        else{
            if (!dfs(it, adj, ac, vis)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int t;
    cin >> t;

    while (t--){
        int n, m;
        cin >> n >> m;
        vector<int> adj[n + 1];
        vector<int> vis(n + 1, 0);

        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool f = true;
        for(int i = 1; i <= n; i++){
            if(vis[i] == 0){
                if(!dfs(i, adj, 1, vis)){
                    f = false;
                    break;
                }
            }
        }

         if(f){
            vector<int> a, b;
            for(int i = 1; i <= n; i++){
                if(vis[i] == 1){
                    a.push_back(i);
                } 
                else{
                    b.push_back(i);
                }
            }
            cout<<"Bob"<<endl;
            int i1 = 0, i2 = 0;
            for(int i = 0; i < n; i++){
                int x, y;
                cin >> x >> y;
                if((x == 1 || y == 1) && i1 < a.size()){
                    cout << a[i1++] << " " << 1<<endl;
                } 
                else if(i2 < b.size()){
                     int num = 3;
                     if(x == 2 || y == 2){
                         num = 2;
                     }
                    cout << b[i2++] << " " << num<<endl ;
                } 
                else if(i1 < a.size()){
                    cout << a[i1++] << " " <<3 <<endl;
                }
            }
        } 
        else{
            cout<<"Alice"<<endl;
            for(int i = 0; i < n; i++){
                cout <<1<<" "<<2<<endl;
                int u, v;
                cin >> u >> v;
            }
        }
    }
    return 0;
}
