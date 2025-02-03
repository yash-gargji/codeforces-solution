#include <bits/stdc++.h>
using namespace std;
#define int long long

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

signed main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, p;
        cin >> n >> p;
         vector<int>v(n);
         int mod = 1e9 + 7;
         int num = 0;
         
         for(int i = 0;i<n;i++){
             cin>>v[i];
             if(v[i] == 0){
               num++;
             }
         }
         if(num == 0 ){
           cout<<"0\n";
           continue;
         }
         int flag = 1;
         int k = 0;
         
         for(int i = 0;i<n/2;i++){
              if(v[i] != v[n - i - 1]){
                if(v[i] == 0 || v[n-i-1] == 0){
                    k++;
                }
                else{
                    flag = 0;
                }
              }
         }
         if(flag == 0){
            cout<<binpow(p,num,mod)<<endl;
            continue;
         }
         if(num == 1){
            cout<<p<<endl;
            continue;
         }
         int ans = binpow(p, num, mod);
         num = num - k;
        int a = (p * (p - 1) / 2) % mod;
        if(num <= 1)
          a = 0;
        
        int neg = (a * binpow(p, num - 2, mod)) % mod;
        cout << (ans - neg + mod) % mod << endl;
    }

    return 0;
}
