#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
 
    if (n == 2) {
        if (s[0] == '0') {
            cout << s[1] << endl;
        } else {
            cout << s << endl;
        }
        return;
    }
 
    bool hasZero = false;
    for (char it : s) {
        if (it == '0') {
            hasZero = true;
            break;
        }
    }
 
    if (hasZero) {
       
        if (n >= 4) {
            cout << '0' << endl;
        } else {
           
            if (s[1] == '0') {
                int num1 = s[0] - '0';
                int num2 = s[2] - '0';
                int num = min(num1 + num2, num1 * num2);
                cout << num << endl;
            } else {
                cout << '0' << endl;
            }
        }
        return;
    }
 
    long long int ans = LLONG_MAX;
    for (int i = 0; i <= n - 2; i++) {
        vector<int> vec;
        for (int j = 0; j < n; j++) {
            if (j == i) {
               
                string st = "";
                st += s[j];
                st += s[j + 1];
                j++;
                vec.push_back(stoi(st));
            } else {
               
                string st = "";
                st += s[j];
                vec.push_back(stoi(st));
            }
        }

        long long int num = vec[0];
        if (num == 1) num = 0;

        for (int k = 1; k < vec.size(); k++) {
            if (vec[k] != 1) {
                num += vec[k];
            }
        }

        ans = min(ans, num);
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
