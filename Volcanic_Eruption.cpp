#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, p;
        cin >> n >> p;
        vector<int> v(n), pre(n, 0), suff(n, 0);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int num = 0;
        int flag = 1;
        for (int i = 0; i < n; i++) {
             if(flag && v[i] != 0)
                pre[i] = INT_MAX;
            else if (v[i] == 0) {
                num = 0;
                flag = 0;
            } else {
                num = max(num, v[i]);
                pre[i] = num;
            }
        }

        num = 0;
        flag = 1;
        for (int i = n - 1; i >= 0; i--) {
            if(flag && v[i] != 0)
              suff[i] = INT_MAX;
            
            else if (v[i] == 0) {
                num = 0;
                flag = 0;
            } else {
                num = max(num, v[i]);
                suff[i] = num;
            }
        }

        for (int i = 0; i < n; i++) {
            int k = (pre[i] == 0 || suff[i] == 0) ? v[i] : min(pre[i], suff[i]);
            cout << (int)ceil((double)k / p) << " ";
        }
        cout << endl;
    }

    return 0;
}
