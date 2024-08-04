#include <bits/stdc++.h>
using namespace std;

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
        int n;
        cin >> n;
        long long ans = 0;
        long long mod = 1e9 + 7;
        
        for (int i = 1; i <= n - 1; i++) {
            long long num = (i * i) % mod;
            num = (num * (n - i)) % mod;
            num = (num * binpow(2, n - i, mod)) % mod;
            
            ans = (ans + num) % mod;
        }
        cout << ans << endl;
    }
}
