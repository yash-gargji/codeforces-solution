#include<bits/stdc++.h>
using namespace std;

int main(){
      ios_base::sync_with_stdio(false);
      int n,m;
      cin>>n>>m;
      map<pair<long long,long long >,int>mp;

      for(int i = 0;i<n;i++){
          string s;
          cin>>s;
          const int mod = 1e9 + 9;
          long long  hash1 = 0,hash2 = 0;
          int base1 = 31;
          int base2 = 29;
          long long int num1 = 1,num2 = 1;

          for(int j = 0;j<s.size();j++){
              hash1 = hash1 + ((s[j] - 'a' + 1)*num1)%mod;
              hash1 %= mod;
              num1 = (num1 * base1)%mod;
              hash2 = hash2 + ((s[j] - 'a' + 1)*num2)%mod;
              hash2 %= mod;
              num2 = (num2 * base2)%mod;
          }
         mp[{hash1,hash2}] = 1;
      }
      for(int i = 0;i<m;i++){
          string s;
          cin>>s;
          const int mod = 1e9 + 9;
          long long  hash1 = 0,hash2 = 0;
          int base1 = 31;
          int base2 = 29;
          long long int num1 = 1,num2 = 1;
          vector<long long>b1(s.size()),b2(s.size());

          for(int j = 0;j<s.size();j++){
              hash1 = hash1 + ((s[j] - 'a' + 1)*num1)%mod;
              hash1 %= mod;
              b1[j] = num1;
              num1 = (num1 * base1)%mod;
              hash2 = hash2 + ((s[j] - 'a' + 1)*num2)%mod;
              hash2 %= mod;
              b2[j] = num2;
              num2 = (num2 * base2)%mod;
          }
            int f = 0;
            for(int j = 0; j < s.size(); j++) {
                for(char c = 'a'; c <= 'z'; c++) {
                    if(s[j] != c) {
                        long long int k1 = (hash1 + mod + ((c - s[j] ) * b1[j]) % mod) % mod;
                        long long int k2 = (hash2 + mod + ((c - s[j] ) * b2[j]) % mod) % mod;
                        if(mp.find({k1,k2}) != mp.end()) {
                            f = 1;
                            break;
                        }
                    }
                }
                if(f) break;
            }
         if(f) printf("YES\n");
         else printf("NO\n");
      }
}