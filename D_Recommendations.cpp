#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> ans(n);
        vector<vector<int>> v(n);
        set<pair<int, int>> s1;
        set<int> s;

        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            v[i] = {l, r, i};
        }

        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        for (int i = 0; i < n; i++) {
            int r = INT_MAX, l = INT_MIN;

            auto it = s.lower_bound(v[i][1]);
            if (it != s.end()) r = *it;

            if (i < n - 1 && v[i][0] == v[i + 1][0]) {
                r = min(r, v[i + 1][1]);
                l = v[i][0];
            }

            auto itr = s1.lower_bound({r,0});
            if (itr != s1.end()) l = max(l, itr->second);
           
            if (l == INT_MIN || r == INT_MAX) {
                ans[v[i][2]] = 0;
            } 
            else {
                ans[v[i][2]] = r - l + 1 - (v[i][1] - v[i][0] + 1);
            }
            while(!s1.empty()) {
                auto p = *s1.begin();
                if (p.first <= v[i][1])
                    s1.erase(s1.begin());
                else
                    break;
            }
            s1.insert({v[i][1], v[i][0]});
            s.insert(v[i][1]);
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
