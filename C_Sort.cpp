#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;
        string s, t;
        cin >> s >> t;

        vector<vector<int>> v1(n, vector<int>(26, 0));
        vector<vector<int>> v2(n, vector<int>(26, 0));

        for (int i = 0; i < n; i++) {
            v1[i][s[i] - 'a']++;
            v2[i][t[i] - 'a']++;

            if (i > 0) {
                for (int j = 0; j < 26; j++) {
                    v1[i][j] += v1[i - 1][j];
                    v2[i][j] += v2[i - 1][j];
                }
            }
        }

        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            vector<int> f1 = v1[r];
            vector<int> f2 = v2[r];

            if (l > 0) {
                for (int j = 0; j < 26; j++) {
                    f1[j] -= v1[l - 1][j];
                    f2[j] -= v2[l - 1][j];
                }
            }

            int count = 0;
            for (int j = 0; j < 26; j++) {
                if (f2[j] > f1[j]) {
                    count += f2[j] - f1[j];
                }
            }
            cout << count << endl;
        }
    }
    return 0;
}
