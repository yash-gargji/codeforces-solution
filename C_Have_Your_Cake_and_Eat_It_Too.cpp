#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> v(3, vector<int>(n + 1));
        vector<vector<int>> p = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 1, 0}, {2, 0, 1}};
        long long sum = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
                if(i == 0)
                  sum += v[i][j];
            }
        }
         sum = (sum + 2) / 3;

        vector<int> ans(6);
        bool flag = false;

        for (int i = 0; i < 6; i++) {
            long long sum1 = 0, sum2 = 0, sum3 = 0;
            int la = -1, ra = -1, lb = -1, rb = -1, lc = -1, rc = -1;
            int prev = 0;

            for (int j = 0; j < 3; j++) {
                if (p[i][j] == 0) {
                    la = prev;
                    while (prev < n && sum1 < sum) {
                        sum1 += v[0][prev++];
                    }
                    ra = prev - 1;
                } else if (p[i][j] == 1) {
                    lb = prev;
                    while (prev < n && sum2 < sum) {
                        sum2 += v[1][prev++];
                    }
                    rb = prev - 1;
                } else {
                    lc = prev;
                    while (prev < n && sum3 < sum) {
                        sum3 += v[2][prev++];
                    }
                    rc = prev - 1;
                }
            }

            if (sum1 >= sum && sum2 >= sum && sum3 >= sum) {
                flag = true;
                ans[0] = la + 1;
                ans[1] = ra + 1;
                ans[2] = lb + 1;
                ans[3] = rb + 1;
                ans[4] = lc + 1;
                ans[5] = rc + 1;
                break;
            }
        }

        if (!flag) {
            cout << -1 << endl;
        } else {
            for (int i = 0; i < 6; i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
