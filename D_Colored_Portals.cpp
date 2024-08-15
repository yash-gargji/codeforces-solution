#include<bits/stdc++.h>
using namespace std;

int func(string s, map<string, vector<int>>& m, int a, int b) {
    int ans = INT_MAX;
    if(m[s].size() == 0) {
        return ans;
    }

    auto it = lower_bound(m[s].begin(), m[s].end(), a);

    if(it != m[s].end()) {
        ans = min(ans, abs(a - *it) + abs(*it - b));
    }
    
    if(it != m[s].begin()) {
        it--; 
        ans = min(ans, abs(a - *it) + abs(*it - b));
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, q;
        cin >> n >> q;
        map<string, vector<int>> m;
        vector<string> v;

        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            v.push_back(s);
            m[s].push_back(i);
            reverse(s.begin(), s.end());
            m[s].push_back(i);
        }

        for(int i = 0; i < q; i++) {
            int a, b;
            cin >> a >> b;
            if(b < a) {
                swap(a, b);
            }
            a--;
            b--;

            int ans = INT_MAX;

            if(v[a][0] == v[b][0] || v[a][0] == v[b][1] || v[a][1] == v[b][0] || v[a][1] == v[b][1]) {
                cout << abs(a - b) << endl;
                continue;
            }

            ans = min(ans, func(string(1, v[a][0]) + string(1, v[b][0]), m, a, b));
            ans = min(ans, func(string(1, v[a][0]) + string(1, v[b][1]), m, a, b));
            ans = min(ans, func(string(1, v[a][1]) + string(1, v[b][0]), m, a, b));
            ans = min(ans, func(string(1, v[a][1]) + string(1, v[b][1]), m, a, b));

            if(ans == INT_MAX) {
                cout << "-1\n";
            } else {
                cout << ans << endl;
            }
        }
    }
}
