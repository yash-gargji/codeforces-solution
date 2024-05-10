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

         if(2*a <= b)
         {
            cout<<a*n<<endl;
         }
         else{
              cout<<(n/2)*b +(n%2)*a<<endl;
         }
    }
}