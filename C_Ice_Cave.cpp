#include <bits/stdc++.h>
using namespace std;

int r1, c1, r2, c2;
int n, m;
int delrow[4] = {-1, 0, 1, 0};
int delcol[4] = {0, -1, 0, 1};

bool dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& mat) {
    vis[row][col] = 1;

    for (int i = 0; i < 4; i++) {
        int arow = delrow[i] + row;
        int acol = delcol[i] + col;

        if (arow < 1 || arow > n || acol < 1 || acol > m)
            continue;
        if (arow == r2 && acol == c2)
            return true;
        if (!vis[arow][acol] && mat[arow][acol] != 'X') {
            if (dfs(arow, acol, vis, mat))
                return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    vector<vector<char>> mat(n + 1, vector<char>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mat[i][j];
        }
    }
     cin >> r1 >> c1 >> r2 >> c2;

    if (mat[r2][c2] == 'X') {
        vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));

        if (dfs(r1, c1, vis, mat) == true)
            cout << "YES\n";
        else
            cout << "NO\n";
    } 
    else {
        bool flag = false;

        for (int i = 0; i < 4; i++) {
            int arow = delrow[i] + r2;
            int acol = delcol[i] + c2;

            if (arow < 1 || arow > n || acol < 1 || acol > m)
                continue;

            if (mat[arow][acol] != 'X') {
                vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
                mat[arow][acol] = 'X';  
                if (dfs(r1, c1, vis, mat)) {
                    flag = true;
                    break;
                }
                mat[arow][acol] = '.';
            }
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
