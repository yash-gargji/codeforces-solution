#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        vector<int> v(26, 0);

        for (char ch : s) v[ch - 'A']++;
        for (int i = 0; i < v['T' - 'A']; i++) cout << 'T';
           v['T' - 'A'] = 0;

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < v[i]; j++) {
                cout << char(i + 'A');
            }
        }

        cout << endl;
    }

    return 0;
}
