#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;
      while(t--){
         long long int n,m;
         cin>>n>>m;
         long long int mod = 1000000007;
         long long int product = 1;
         if(n<=m){
              for(int i = 0;i<n;i++){
                product = product *(m-i);
                product = product%mod;
              }
              cout<<product%mod<<endl;
         }
         else{
             for(int i = 0;i<m;i++){
                product = product *(m-i);
                product = product%mod;
              }
              cout<<product%mod<<endl;
         }
      }
}