#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;
      while(t--){
         int a,b,c;
           cin>>a>>b>>c;
           if(2*a - 1< 2*(c+b)){
                 cout<<2*a - 1<<endl;
           }
           else{
            cout<< 2*(c+b) + 1<<endl;
           }
      }
}