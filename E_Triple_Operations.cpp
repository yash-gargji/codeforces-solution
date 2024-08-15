#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
       int l,r;
       cin>>l>>r;
       int ans = 0;
       int mult = 1;
       int num = l;

       while(mult < l){
            mult = mult*3;
       }
       if(mult != l){
          mult = mult/3;
       }
       while(num > 0){
            ans++;
            num = num/3;
       }
       while(mult <= r){
            num = mult;
           int op = 0;
           while(num > 0){
              op++;
              num /= 3;
           }
           int x = max(mult,l);
           int y = min(mult*3 - 1,r);
           ans += (y - x + 1)*op;
           mult = mult*3;
       }
       cout<<ans<<endl;
    }
}