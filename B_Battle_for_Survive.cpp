#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;
      
      while(t--){
           int n;
           cin>>n;
          int arr[n];

          for(int i = 0;i<n;i++){
              cin>>arr[i];
          }
          long long sum = 0;
          
          for(int i = 0;i<n;i++){
              if(i != n-2){
                 sum += arr[i];
              }
          }
         cout<<sum - arr[n-2]<<endl; 
      }
}