#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     std::cin>>t;
     while(t--){  
       unsigned long long int a,b,c;
      std::cin>>a>>b>>c;
         if(a < c){
           std::cout<<"1 ";
         }
         else{
          std::cout<<"-1 ";
         }
         if(a*b >c){
          std::cout<<b<<"\n";
         }
         else{
          std::cout<<"-1\n";
         }
     }
     return 0;
}