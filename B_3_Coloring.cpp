#include <bits/stdc++.h>
using namespace std;

int delrow[4] = {-1, 0, 1, 0};
int delcol[4] = {0, -1, 0, 1};

bool dfs(int i, int j, int c, vector<vector<int>> &vis) {
    vis[i][j] = c;
    int n = vis.size();
    int ac = c == 1 ? 2 : 1;
    
    for (int k = 0; k < 4; k++) {
        int nrow = delrow[k] + i;
        int ncol = delcol[k] + j;
        
        if (nrow < 0 || ncol < 0 || nrow >= n || ncol >= n) {
            continue;
        }
        
        if (vis[nrow][ncol] == c) {
            return false;
        } 
        else if (vis[nrow][ncol] == 0) {
            if (!dfs(nrow, ncol, ac, vis)) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    
    bool isBipartite = dfs(0, 0, 1, vis);
    
    vector<pair<int, int>> a, b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] == 1) {
                a.push_back({i + 1, j + 1});
            } 
            else{
                b.push_back({i + 1, j + 1});
            }
        }
    }
    
    int i1 = 0, i2 = 0;
    for (int i = 0; i < n * n; i++) {
        int k;
        cin >> k;
        int x, y;
        if (k == 1) {
            x = 2;
            y = 3;
        } else if (k == 2) {
            x = 1;
            y = 3;
        } else {
            x = 1;
            y = 2;
        }
        
        if ((x == 1 || y == 1) && i1 < a.size()) {
            cout << 1 << " " << a[i1].first << " " << a[i1].second << endl;
            i1++;
        } 
        else if (i2 < b.size()) {
            int num = 3;
            if (x == 2 || y == 2) {
                num = 2;
            }
            cout << num << " " << b[i2].first << " " << b[i2].second << endl;
            i2++;
        } 
        else if (i1 < a.size()) {
            cout << 3 << " " << a[i1].first << " " << a[i1].second << endl;
            i1++;
        }
    }
    
    return 0;
}
