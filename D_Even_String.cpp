#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;
const int MAX_N = 500000;

int power(int x, int y, int mod) {
    int res = 1;
    x %= mod;
    while (y > 0) {
        if (y & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}

int mod_inv(int x, int mod) {
    return power(x, mod - 2, mod);
}

vector<int> fact(MAX_N + 1, 1), inv_fact(MAX_N + 1, 1);

void precompute_factorials() {
    for (int i = 2; i <= MAX_N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    inv_fact[MAX_N] = mod_inv(fact[MAX_N], mod);
    for (int i = MAX_N - 1; i >= 1; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    }
}

int nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return (fact[n] * inv_fact[r] % mod) * inv_fact[n - r] % mod;
}

signed main() {
    precompute_factorials();
    
    int t;
    cin >> t;

    while (t--) {
        vector<int> v(26);
        int n = 0;

        for (int i = 0; i < 26; i++) {
            cin >> v[i];
            n += v[i];
        }
        int target = n / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < 26; i++) {
            if(v[i] == 0)
              continue;
            for (int j = target; j >= 0; j--) {
                if ( j - v[i] >= 0) {
                    dp[j] = (dp[j] + dp[j - v[i]]) % mod;
                }
            }
        }
        int ans = (fact[target] * fact[(n + 1)/2]) % mod;
        ans = (ans * dp[target]) % mod;

        for (int i = 0; i < 26; i++) {
            if (v[i] > 0) {
                ans = (ans * inv_fact[v[i]]) % mod;
            }
        }

        cout << ans<< '\n';
    }
}
