#include<bits/stdc++.h>
using namespace std;

int main(){
    
        long long int n;
           cin>>n;
         long long int a,b,c;
           cin>>a>>b>>c;
         int count = 4 - n%4;
          if(count == 4){
              cout<<0;
          }
          else if(count == 1){
                cout<<min(min(b + c,a),3*c);
          }
          else if(count == 2){
                cout<<min(min(2*c,b),2*a);
          }
          else if(count == 3){
                  cout<<min(a+b,min(c,3*a));
          }
}