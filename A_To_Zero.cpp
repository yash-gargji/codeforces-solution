#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        if (n <= k) {
            cout << 1 << endl;
            continue;
        }

        if (n % 2 == 0) {
            cout << (n + (k - 2)) / (k - 1) << endl;
        } else {
            n -= k;
            cout << 1 + (n + (k - 2)) / (k - 1) << endl;
        }
    }
}
