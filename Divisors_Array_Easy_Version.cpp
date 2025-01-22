#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;

int mod_exp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int mod_inverse(int x, int mod) {
    return mod_exp(x, mod - 2, mod);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int MAXN = 1e7 + 1;
    vector<int> v(MAXN);
    iota(v.begin(), v.end(), 0);

    vector<int> prime;
    for (int i = 2; i * i < MAXN; i++) {
        if (v[i] == i) {
            prime.push_back(i);
            for (int j = i * i; j < MAXN; j += i) {
                if (v[j] == j) {
                    v[j] = i;
                }
            }
        }
    }

    int n, m;
    cin >> n >> m;

     map<int, int> mp;
    for (int p : prime) {
        if (p > m) break;
        int power = p;
        int count = 1;
        while (power <= m) {
            mp[p] += count*(m / power);
            power *= p;
        }
    }

    long long factorial_divisors = 1;
    for (auto &it : mp) {
        factorial_divisors = (factorial_divisors * (it.second + 1)) % MOD;
    }

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        map<int, int> p;
        while (num != 1) {
            p[v[num]]++;
            num /= v[num];
        }

        long long total_divisors = factorial_divisors;
        for (auto &it : p) {
            int pr = it.first;
            int count = it.second;
            if (mp.count(pr)) {
                total_divisors = (total_divisors * (mp[pr] + count + 1) % MOD) *
                                 mod_inverse((mp[pr] + 1), MOD) % MOD;
            } else {
                total_divisors = (total_divisors * (count + 1)) % MOD;
            }
        }

        cout << total_divisors % MOD << " ";
    }

    return 0;
}
