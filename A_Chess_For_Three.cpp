#include<bits/stdc++.h>
using namespace std;

void solve(){
         int a,b,c;

          cin>>a>>b>>c;

         int k = a%2 + b%2 + c%2;
          if(k%2){
           cout<<"-1\n";
          }

     else  if(c >= a+b)
        cout<<a+b<<endl;
        else  
        cout<<c + (a+b - c)/2<<endl;
 }

int  main(){
     int t;
     cin>>t;
     
     while(t--){
         solve();
     }
}