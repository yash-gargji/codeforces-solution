#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
         int n,k;
         cin>>n>>k;

         int num = n;
         int len = n;
         if(k != 1)
            while(len >= k){
                if(len % 2){
                    num = (len + 1)/2;
                }
                len = len/2;
            }
         else
          num = 1;
         int p = n/num;
         if(num == n){
           p = 0;
         }
         cout<<num*p*(p+1)/2<<endl;
    }
}