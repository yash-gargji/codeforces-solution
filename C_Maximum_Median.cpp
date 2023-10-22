#include<bits/stdc++.h>
using namespace std;

int main(){
      int n,k;
      cin>>n>>k;

     int arr[n];

     for(int i = 0;i<n;i++){
        cin>>arr[i];
     } 
     sort(arr,arr+n);
         int count = 1;
         int num = arr[n/2];

      for(int i = n/2 + 1;i<n;i++){

            if(arr[i] == num){
                count++;
                  if(i == n-1){
                        num += k/count;
                        k = 0;
                    
                 }
            }    
            else{
               int p = k/count;
               if(p <= arr[i] - num ){
                  k = 0;
                  num = num + p;
                  break;
               }
               else{
                k = k - count*(arr[i] - num);
                    count++;
                  num = arr[i] ;
               }
            }
      }
          num = num + k/count;
      cout<<num;
}