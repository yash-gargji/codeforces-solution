#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         int a,b;
         cin>>a>>b;
         
         if(abs(a - b) % 2 == 0){
             cout<<"YES\n";
         }
         else{
           cout<<"NO\n";
         }
    }
}