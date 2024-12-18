#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        long long ans = 0;

        for(int i = 1; i <= m; i++) {
            int num = m / i;
            long long count;
            if (m % i == 0) {
                count = 1LL * i * num * num % mod;
            } 
            else {
                count = (1LL * (m % i) * (num + 1) * (num + 1) % mod + 
                         1LL * (i - m % i) * num * num % mod) % mod;
            }
            ans = (ans + binpow(count, n / 2, mod)  % mod) % mod;
        }
        ans = ans * (n % 2 ? m : 1) % mod;
        ans = (ans - (binpow(m, n / 2 + n % 2, mod)*(m+1)) % mod + mod) % mod;
        cout << ans << endl;
    }
    return 0;
}
