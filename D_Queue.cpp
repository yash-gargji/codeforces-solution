#include<bits/stdc++.h>
using namespace std;

int main(){

    int a;
    cin>>a;

    long long int arr[a] ;
      for(int i = 0;i<a;i++){
        cin>>arr[i];
      }
      sort(arr,arr+a);
     int count =  1 ;
     unsigned long long int sum = arr[0];
      for(int i = 1;i<a;i++){
         if(arr[i] >= sum){
            count++;
            sum = sum + arr[i];
         }
         else{
           long long int num = 0;
        
           for(int j = i+1;j<a;j++){
            if(arr[j] >= sum){
                num = arr[j];
                i = j;
                count++;
                break;
            }
            else{
                continue;
            }
           }
           sum = sum + num;
         }
      }
      cout<<count;
      return 0;
}