#include<bits/stdc++.h>
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
    return res%m;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int l,r,k;
        cin>>l>>r>>k;
        long long int mod = 1e9 + 7;
        if(k > 9){
          cout<<0<<endl;
          continue;
        }
       int count = 0;

       for(int i = 0;i<= 9;i++){
          if(k*i < 10)
            count++;
       }
       long long int ans = ((binpow(count,l,mod)*(binpow(count,r-l,mod))*(count-1)) /(count-1) - binpow(count,l,mod) + mod)%mod;

       cout<<ans<<endl;
    }
}