#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin>>n;
       int a ,b;

       for(int i = 0;i<n;i++){
           int num;
           cin>>num;
           if(i == 0){
             a = num;
             b = 0;
           }
           else {
            int temp1 = num + b;
            int temp2 = max(a,b);
            a = temp1;
            b = temp2;
           }
       }
      cout<<max(a,b);
  return 0;
}

