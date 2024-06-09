#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
     
         int  x,y;

         cin>>x>>y;

          int k = 0;

          while((1 << k) <= max(x,y)){
                 int num1 = (1 << k)&x;
                 int num2 = (1 << k)&y;
                 if(num1 != num2){
                      break;
                 }
                k++; 
          }
        cout<<(long long int)pow(2,k)<<endl;
    }
}