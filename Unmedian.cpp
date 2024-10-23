#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n), vis(n, 1);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        vector<pair<int, int>> ans;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) continue;
            int num = i;

            while (true) {
                int l = num - 1;
                int r = num + 1;

                while (l >= 0 && vis[l] == 0) l--;
                while (r < n && vis[r] == 0) r++;

                if (l < 0 || r >= n) break;

                if (v[l] >= v[num] && v[r] >= v[num]) {
                    int count = 0;
                    for (int j = 0; j <= num; j++) {
                        count += vis[j];
                    }
                    ans.push_back({count - 1, count + 1});

                    if (v[l] == v[num]) {
                        vis[l] = 0;
                    } else if (v[num] == v[r]) {
                        vis[num] = 0;
                        num = r;
                    } else if (v[l] <= v[r]) {
                        vis[l] = 0;
                    } else {
                        vis[r] = 0;
                    }
                } else if (v[l] <= v[num] && v[r] <= v[num]) {
                    int count = 0;
                    for (int j = 0; j <= num; j++) {
                        count += vis[j];
                    }
                    ans.push_back({count - 1, count + 1});

                    if (v[l] == v[num]) {
                        vis[l] = 0;
                    } else if (v[num] == v[r]) {
                        vis[num] = 0;
                        num = r;
                    } else if (v[l] >= v[r]) {
                        vis[l] = 0;
                    } else {
                        vis[r] = 0;
                    }
                } else {
                    break;
                }
            }
        }

        int f = 1;
        int prev = -1;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 1) {
                if (v[i] >= prev) {
                    prev = v[i];
                } else {
                    f = 0;
                    break;
                }
            }
        }

        if (!f) {
            cout << "-1\n";
        } else {
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i].first << " " << ans[i].second << endl;
            }
        }
    }
}
