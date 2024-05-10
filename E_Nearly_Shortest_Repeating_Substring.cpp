#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long int n;
        cin >> n;
        string s;
        cin >> s;

        long long int count = LLONG_MAX; 

        long long int k = sqrt(n);

        for (long long int i = 1; i <= k; i++) {
            if (n % i == 0) {
                long long int l = 0;
                for (long long int j = 0; j < i; j++) {
                    ll mxi = 0, total = 0;
                    map<int, ll> m;
                    for (ll k = j; k < n; k += i) {
                        m[s[k] - 'a'] += 1;
                        mxi = max(mxi, m[s[k] - 'a']);
                        total += 1;
                    }
                    l += (total - mxi);
                }
                if (l <= 1) {
                    count = min(count, i);
                }
                if (n / i != i) {
                    long long int l = 0;
                    for (long long int j = 0; j < n / i; j++) {
                        ll mxi = 0, total = 0;
                        map<int, ll> m;
                        for (ll k = j; k < n; k += n / i) {
                            m[s[k] - 'a'] += 1;
                            mxi = max(mxi, m[s[k] - 'a']);
                            total += 1;
                        }
                        l += (total - mxi);
                    }
                    if (l <= 1) {
                        count = min(count, n / i);
                    }
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}
