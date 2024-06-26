#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
    
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
      
        vector<vector<int>> b(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            string str;
            cin >> str;
            for (int j = 0; j < m; ++j) {
                b[i][j] = str[j] - '0';
            }
        }
       
        ll s1 = 0, s2 = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (b[i][j] == 1)
                    s1 += a[i][j];
                else
                    s2 += a[i][j];
            }
        }
        
        ll target = abs(s1 - s2);
        if (k == 1 || target == 0) {
            cout << "YES\n";
            continue;
        }
      
        vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pre[i + 1][j + 1] = b[i][j] + pre[i + 1][j] + pre[i][j + 1] - pre[i][j];
            }
        }
       
        set<int> st;
        for (int i = k; i <= n; ++i) {
            for (int j = k; j <= m; ++j) {
                int num = pre[i][j] - pre[i - k][j] - pre[i][j - k] + pre[i - k][j - k];
                st.insert(abs(2 * num - k * k));
            }
        }
      
        bool flag = false;
        int gcd = 0;
        for (int val : st) {
            if (val != 0 && target % val == 0) {
                flag = true;
            }
            gcd = __gcd(gcd, val);
        }
        
        if (gcd != 0 && target % gcd == 0) {
            flag = true;
        }
        
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
