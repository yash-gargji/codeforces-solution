#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> v(26, 0);

        int arr[m];
        for (int i = 0; i < m; i++) {
            cin >> arr[i];
            arr[i]--;
        }
        set<int> st(arr, arr + m);
        string c;
        cin >> c;

        for (int i = 0; i < n; i++) {
            v[c[i] - 'a']++;
        }

        int ind = 0;
        for (auto it : st) {
            while (v[ind] == 0) {
                ind++;
            }
            
                s[it] = 'a' + ind;
                v[ind]--;
        }
        cout << s << endl;
    }
    return 0;
}
