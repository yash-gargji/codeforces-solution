#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> f(n);
        vector<int> h(n);

        for (int i = 0; i < n; i++) {
            cin >> f[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }

        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            if (h[i] % h[i + 1] == 0) {
                int l = i;
                int r = i;

                for (int j = i + 1; j < n - 1; j++) {
                    if (h[j] % h[j + 1] == 0) {
                        r = j;
                    } else {
                        break;
                    }
                }
                i = r;
                r++;

                int sum = 0;
                int p = l;

                for (int i = l; i <= r; i++) {
                    sum += f[i];

                    while (sum > k && p <= i) {
                        sum -= f[p++];
                    }

                    if (sum <= k) {
                        ans = max(ans, i - p + 1);
                    }
                }
            }
        }
        if(ans == 0 && *min_element(f.begin(),f.end()) <= k){
               ans = 1;
        }

        cout << ans << endl;
    }

    return 0;
}
