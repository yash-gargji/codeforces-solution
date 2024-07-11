#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n][m] , b[n][m];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char c;
                cin >> c;
                a[i][j] = c - '0';
            }
        }
 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char c;
                cin >> c;
                b[i][j] = c - '0';
            }
        }

        int ans = 1;
 
        for (int i = n - 1; i > 0; --i) {
            for (int j = m - 1; j > 0; --j) {
                if (a[i][j] != b[i][j]) {
                    int d = (b[i][j] - a[i][j] + 3) % 3;
                    a[i][j] = b[i][j];
                    a[i - 1][j] = (a[i - 1][j] + 2 * d) % 3;
                    a[i][j - 1] = (a[i][j - 1] + 2 * d) % 3;
                    a[i - 1][j - 1] = (a[i - 1][j - 1] + d) % 3;
                }
            }
        }
 
        for (int i = 0; i < n; ++i) {
            if (a[i][0] != b[i][0]) {
                ans = 0;
            }
        }
        for (int j = 0; j < m; ++j) {
            if (a[0][j] != b[0][j]) {
                ans = 0;
            }
        }

        if (ans == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
