#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
       int n,a,b,c;
       cin>>n>>a>>b>>c;
       
       int num = a + b + c;
       int ans = n/num;
       n -= ans*num;
       ans = ans*3;
       
       if(n > 0){
         ans++;
         n -= a;
       }
       if(n > 0){
         ans++;
         n -= b;
       }
       if(n > 0){
         ans++;
         n -= c;
       }
       cout<<ans<<endl;
    }
}