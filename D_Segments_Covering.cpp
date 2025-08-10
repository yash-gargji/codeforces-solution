#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long r = 1;
    while (b) {
        if (b & 1) r = r * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return r;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<array<int,4>> v(n);
    int a = 1;
    for(int i = 0; i < n; i++){
        cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];
        int p = v[i][2], q = v[i][3];
        int h = (q - p + mod) % mod * binpow(q, mod-2, mod) % mod;
        a = a * h % mod;
    }

    sort(v.begin(), v.end());

    vector<int> dp(m+2);
    dp[m+1] = 1;
    for(int i = n - 1; i >= 0; i--){
        int l = v[i][0], r = v[i][1];
        int p = v[i][2], q = v[i][3];
        int w = p * binpow((q - p + mod) % mod, mod-2, mod) % mod;
        dp[l] = (dp[l] + w * dp[r+1]) % mod;
    }

    cout << a * dp[1] % mod;
    return 0;
}
