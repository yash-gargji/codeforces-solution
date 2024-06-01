#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

void multiply(vector<vector<long long>>&a,vector<vector<long long>>&b)
{
     int n = a.size();
     vector<vector<long long>>mul(a.size(),vector<long long >(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mul[i][j] = 0;
            for (int k = 0; k < n; k++)
                mul[i][j] += (a[i][k] * b[k][j]) % mod;
                mul[i][j] %= mod;
        }
    }
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a[0].size(); j++)
            a[i][j] = mul[i][j];
}
void pow(vector<vector<long long >>&F, long long  n){
   vector<vector<long long >>M = F;
    while (n) {
        if (n & 1) {
            multiply(F, M);
        }
        multiply(M, M);
        n >>= 1;
    }
}

int main(){
     long long  int n,k;
     cin>>n>>k;
     vector<long long int>arr(n);
     for(int i = 0;i<n;i++){
         cin>>arr[i];
     }
      if(k == 1){
         cout<<n;
         return 0;
      }
      vector<vector<long long >>mat(n,vector<long long >(n));

      for(int i = 0;i<n;i++){
         for(int j = 0;j<n;j++){
              int num = __builtin_popcountll(1ll*arr[i]^arr[j]);
             if(num%3 == 0){
                 mat[i][j] = 1;
             }
         }
      }
     if(k > 2)
      pow(mat,k-2);
      long long ans = 0;

      for(int i = 0;i<n;i++){
         for(int j = 0;j<n;j++){
             ans += mat[i][j];
             ans %= mod;
         }
        cout<<endl;
      }
    cout<<ans<<endl;
}