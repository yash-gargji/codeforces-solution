#include<bits/stdc++.h>
using namespace std;

int main(){
   int a;
   cin>>a;
   
   int z = a/10;
   a = a+z;
     int num = a%10;
     z = a/10;
     if(num == 0){
        cout<<1;
        for(int i = 0;i<z;i++){
            cout<<0;
        }
        cout<<9;
     }
     else{
        cout<<num;
         for(int i = 0;i<z;i++){
            cout<<0;
        }
        cout<<10-num;
     }
     return 0;

}