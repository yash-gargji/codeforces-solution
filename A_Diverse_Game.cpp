#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[n][m];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        
        if (n == 1 && m == 1) {
            cout << "-1\n";
            continue;
        }

        vector<int> v(n * m + 1, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int num = -1;
                for (int ind = 1; ind <= n * m; ind++) {
                    if (arr[i][j] != ind && v[ind] != 1) {
                        v[ind] = 1;
                        num = ind;
                        break;
                    }
                }
                cout << num << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
