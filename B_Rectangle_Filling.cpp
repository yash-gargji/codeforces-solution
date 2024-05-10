#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        char arr[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        int flag = 0;
        if (m == 1) {
            if (arr[0][0] == arr[n - 1][0]) {
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
        else if (n == 1) {
            if (arr[0][0] == arr[0][m - 1]) {
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
        else {
            // Column-wise check
            for (int i = 0; i < m; i++) {
                int f1 = 0, f2 = 0;
                if (arr[0][i] == arr[n - 1][i]) {
                    if (i == 0) f1 = 1;
                    if (i == m - 1) f2 = 1;
                    for (int j = 0; j < n; j++) {
                        if (arr[j][0] == arr[0][i])
                            f1 = 1;
                        if (arr[j][m - 1] == arr[0][i]) {
                            f2 = 1;
                        }
                    }
                }
                if (f1 && f2) {
                    flag = 1;
                    cout << "YES\n";
                    break;
                }
            }

            // Row-wise check
            for (int i = 0; i < n; i++) {
                int f1 = 0, f2 = 0;
                if (arr[i][0] == arr[i][m - 1]) {
                    if (i == 0) f1 = 1;
                    if (i == n - 1) f2 = 1;
                    for (int j = 0; j < m; j++) {
                        if (arr[0][j] == arr[i][0])
                            f1 = 1;
                        if (arr[n - 1][j] == arr[i][0]) {
                            f2 = 1;
                        }
                    }
                }
                if (f1 && f2 && flag==0) {
                    flag = 1;
                    cout << "YES\n";
                    break;
                }
            }

            if (!flag)
                cout << "NO\n";
        }
    }
    return 0;
}
