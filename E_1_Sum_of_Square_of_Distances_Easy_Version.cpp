 #include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        
        long long int mod = 1e9 + 7;
        long long int sum1 = 0, sum2 = 0, sq = 0;
        for(int i = 0; i < n; i++) {
            long long int num1, num2;
            cin >> num1 >> num2;
            long long int k = num1 * num1 % mod;
            sum1 = sum1 + num1;
            sum2 = sum2 + num2;
            sum1 = sum1 % mod;
            sum2 = sum2 % mod;
            sq = (sq + k) % mod;
            k = num2 * num2 % mod;
            sq = (sq + k) % mod;
        }
        
        long long int q;
        cin >> q;
        sq = sq*q;
        sq = sq%mod;
        long long int neg = 0;
        for (int i = 0; i < q; i++) {
            long long int num1, num2;
            cin >> num1 >> num2;
            
            long long int k = num1 * num1 % mod;
            k = (k * n) % mod;
            sq = (sq + k) % mod;
            
            k = num2 * num2 % mod;
            k = (k * n) % mod;
            sq = (sq + k) % mod;
            
            long long int num = 2 * sum1 * num1 % mod;
            neg = (neg - num ) ;
            
            num = 2 * sum2 * num2 % mod;
            neg = (neg - num) ;
            
        } 
        
        long long int ans = (sq + neg);
        while(ans < 0){
            ans += mod;
        }
        cout << ans << endl;
    }
}
