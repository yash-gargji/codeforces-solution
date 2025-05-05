#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int p[N], sz[N];

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) p[u] = v, sz[v] += sz[u];
}

signed main() {
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n), q(n);

        for (int i = 1; i <= n; i++) 
            p[i] = i, sz[i] = 1;

         for(int i = 0;i<n;i++){
            cin>>arr[i];
         }
         for(int i = 0;i<n;i++){
            cin>>q[i];
         }

        for (int i = 0; i < n; i++){
            if (arr[i] >= 1 && arr[i] <= n) 
               merge(i + 1, arr[i]);
        }
        set<int> st;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int par = find(q[i]);
            if (!st.count(par)) 
                st.insert(par), ans += sz[par];
            cout << ans << " ";
        }
        cout << endl;
    }
}