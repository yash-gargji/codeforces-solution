#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

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

signed main(){
    int t;
    cin >> t;
    
    while (t--){
        int n;
        cin >> n;
        int ma = 0;    
        int sum = 0;   
        stack<pair<int,int>>st;

        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            int count = 0;
            int flag = 0;
            int a = num;    

            while(!st.empty() && (num >= st.top().first || flag )){
               sum = sum - (binpow(2,st.top().second,mod) * st.top().first) % mod;
               sum = (sum + mod) % mod;
               count += st.top().second;
               int k = st.top().first;
               st.pop();
               while(k % 2 == 0){
                  count++;
                  k = k / 2;
               }
               sum += k;
               sum = sum % mod;
               num = (binpow(2,count,mod) * a);
               if(num >= 1e9){
                  flag = 1;
                  num = num % mod;
               }
            }
          sum = sum + (binpow(2,count,mod) * a) % mod;
          sum = sum % mod;
          while(a % 2 == 0){
             a = a / 2;
             count++;
          }
          st.push({a,count});
          cout<<sum<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
