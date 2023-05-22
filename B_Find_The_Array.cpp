#include<bits/stdc++.h>
using namespace std;

int main(){
   int p;
   cin>>p;
   while(p--){

    long long int t;
     cin>>t;
     long long int arr[t];

     for(int i = 0;i<t;i++){
           cin>>arr[i];
     }
      long long int pre[t];
       pre[0] = arr[0];

       for(int i = 1;i<t;i++){
       if(arr[i] == arr[i-1] ){
                pre[i] = arr[i];
                continue;
            }
         long long int num = (arr[i]) %(arr[i-1]);
            long long int n = (arr[i-1])%(arr[i]);

            if(n == 0 || num == 0 ){
                pre[i] = arr[i];
                continue;
            }

          pre[i] = arr[i] - num;
          arr[i] = pre[i];
       }
       for(int i = 0;i<t;i++){
        cout<<pre[i]<<" ";
       }
       cout<<endl;
   }
   return 0;
}