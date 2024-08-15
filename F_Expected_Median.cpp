#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 2.1e5 + 1;
vector<long long> fact(MAX_N);
vector<long long> invFact(MAX_N);
void precomputeFactorials() {
    fact[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}
long long modInverse(long long x, long long mod) {
    long long result = 1, power = mod - 2;
    while (power) {
        if (power & 1) result = (result * x) % mod;
        x = (x * x) % mod;
        power >>= 1;
    }
    return result;
}
void precomputeInvFactorials() {
    for (int i = 0; i < MAX_N; ++i) {
        invFact[i] = modInverse(fact[i], MOD);
    }
}
long long comb(int n, int k) {
    if (k > n || k < 0) return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

int main() {
    precomputeFactorials();
    precomputeInvFactorials();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int ones = 0, zeros = 0;
        for (int i = 0; i < n; ++i) {
            int c;
            cin >> c;
            if (c == 1) {
                ++ones;
            } else {
                ++zeros;
            }
        }

        long long ans = 0;
        for (int i = (k + 1) / 2; i <= ones; ++i) {
            if (k - i <= zeros && k - i >= 0) {
                long long a = comb(ones, i);
                long long b = comb(zeros, k - i);
                ans = (ans + a * b % MOD) % MOD;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
