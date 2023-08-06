#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int d;
        cin>>d;
       long long int x = 1 + d ,y = 1 + 2*d;
       long long int ans = (x*y)/__gcd(x,y);
      long long  int z = (1 + 3*d);
          if(ans - y < d){
                cout<<(z*ans)/__gcd(z,ans)<<endl;
          }
            else{
               cout<<(x*y)/__gcd(x,y)<<endl;
          }
        
    }
}