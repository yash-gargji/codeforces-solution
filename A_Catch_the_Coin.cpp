#include<bits/stdc++.h>
using namespace std;

 
int main(){
     int t;
     cin>>t;

     while(t--){
         int x,y;
         cin>>x>>y;

         x = abs(x);
         y = y - x + 1;

         if(abs(y) <=  x){
            cout<<"YES\n";
         }
         else{
             cout<<"NO\n";
         }
     }
}