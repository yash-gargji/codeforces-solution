#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> grid(n, vector<char>(m));
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, -1, 0, 1};
    vector<vector<int>> indeg(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                for (int l = 0; l < 4; l++) {
                    int arow = delrow[l] + i;
                    int acol = delcol[l] + j;
                    if (arow >= 0 && acol >= 0 && arow < n && acol < m && grid[arow][acol] == '.') {
                        indeg[i][j]++;
                    }
                }
                if (indeg[i][j] <= 1) {
                    q.push({i, j});
                }
            }
        }
    }

    while (!q.empty() && k > 0) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
       
        grid[row][col] = 'X';
        k--;

        for (int l = 0; l < 4; l++) {
            int arow = delrow[l] + row;
            int acol = delcol[l] + col;

            if (arow >= 0 && acol >= 0 && arow < n && acol < m && grid[arow][acol] == '.') {
                indeg[arow][acol]--;
                if (indeg[arow][acol] <= 1) {
                    q.push({arow, acol});
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}
