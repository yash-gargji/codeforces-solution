#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    int t;
    cin>>t;
    
    while(t--){
         int a,b,c,d;
         cin>>a>>b>>c>>d;

         if(min(a,c) >= min(b,d)){
           cout<<"Gellyfish\n";
         }
         else{
           cout<<"Flower\n";
         }
    }
}