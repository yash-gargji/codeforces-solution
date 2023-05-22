#include<bits/stdc++.h>
using namespace std;
 bool prime(long long int x){
       for(long int i = 3;i<=sqrt(x);i = i+2){
        if(x%i == 0){
            return false;
            break;
        }
       }
       return true;
 }
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int b;
    cin>>b;
    while(b--){
       long long int a;
       cin>>a;
       if(a == 4){
       cout<<"YES\n";
       continue;
       }
      else if(a%2 == 0 || a == 1 || a == 3 || a == 2){
        cout<<"NO\n";
        continue;
       }
        long long int x = sqrt(a);
         
         if(x*x != a ){
            cout<<"NO\n";
         }
         else {
            bool y = prime(x); 
            if(y == false){
                cout<<"NO\n";

            }
            else{
                cout<<"YES\n";
            }
         }
    }
    return 0;
}