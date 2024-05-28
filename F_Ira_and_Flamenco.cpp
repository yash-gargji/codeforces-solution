#include<bits/stdc++.h>
using namespace std;

 int mod = 1e9 + 7;

int modInverse(int A, int M)
{
    int m0 = M;
    int y = 0, x = 1;
    if (M == 1) return 0;
    while (A > 1) {
        int q = A / M, t = M;
        M = A % M, A = t, t = y, y = x - q * y, x = t;
    }
    if (x < 0) x += m0;
    return x;
}

int main(){
      int t;
      cin>>t;

      while(t--){
          int n,m;
          cin>>n>>m;
          map<long long,long long>mp;
          vector<int>v;
          vector<long long>prod;

          for(int i = 0;i<n;i++){
             long long num;
              cin>>num;
              mp[num]++;
          }
          long long num = 1;
          long long ans = 0;
          for(auto it:mp){
              v.push_back(it.first);
              num = (num % mod)*(it.second % mod)%mod;
              num = num%mod;
              prod.push_back(num);
          }
        for(int i = 0;i<v.size();i++){
            auto it = upper_bound(v.begin(),v.end(),v[i] - m) - v.begin();
            if(i - it + 1 == m){
                long long k = prod[i];
                if(it > 0){
                  k = (k * modInverse(prod[it - 1], mod)) % mod;
                }   
                ans += k;
                ans = ans% mod;
            }
        }
      cout<<ans<<endl;
    }
}