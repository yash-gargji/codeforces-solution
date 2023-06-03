#include<bits/stdc++.h>
using namespace std;
 
int main(){
   int t;
   cin>>t;
   while(t--){
     long long int n;
       cin>>n;
       if(n%2 == 0){
        cout<<n/2<<" "<<n/2<<endl;
       }
       else{
         int x = n%10;
         int num = n/10;
         num = num%10;
         if(x == 9 && num%2 == 1){
            cout<<n/2 - 4<<" "<<n/2 +5<<endl;;
         }
         else{
          cout<<n/2<<" "<<n/2 +1<<endl;

         }
       }
   }
}