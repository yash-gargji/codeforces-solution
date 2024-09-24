#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
       int n,k;
       cin>>n>>k;
       int gcd = 0;

       for(int i = 0;i<n;i++){
           int num;
           cin>>num;
           gcd = __gcd(gcd,num);
       }
       if(n == 1){
          if(k <= gcd){
             cout<<k-1<<endl;
          }
          else{
             cout<<k<<endl;
          }
         continue;
       }
       long long int par = 1ll*(gcd - 1)*(n-1);
       if(k > par){
          par = 1ll*gcd*(n-1) + k - par;
          cout<<par<<endl;
          continue;
       }
       int ind = 0;
       int num = -1;

       while(k > 0 && ind < n){
            num++;
            num += min(gcd - 1,k);
            k -= min(gcd-1,k);
            ind++;
       }
       cout<<num<<endl;
    }
}