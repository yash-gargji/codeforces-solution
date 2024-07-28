#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n - 1);
        vector<int> ans(n, 0);

        for (int i = 0; i < n - 1; i++) {
            cin >> arr[i];
        }
        
        for (int i = 0; i < n - 1; i++) {
            ans[i] |= arr[i];
            ans[i + 1] |= arr[i];
        }

        int f = 1;
        for (int i = 0; i < n - 1; i++) {
            if ((ans[i] & ans[i + 1]) != arr[i]) {
                f = 0;
                break;
            }
        }

        if (f) {
            for (int i = 0; i < n; i++) {
                cout << ans[i] << " ";
            }
        } else {
            cout << "-1";
        }
        cout << endl;
    }

    return 0;
}
