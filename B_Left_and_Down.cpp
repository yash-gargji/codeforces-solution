#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
       long long a,b,c;
       cin>>a>>b>>c;

      long long gcd = __gcd(a,b);

      if(a/gcd <= c && b/gcd <= c){
          cout<<"1\n";
      }
      else{
         cout<<"2\n";
      }
    }
}