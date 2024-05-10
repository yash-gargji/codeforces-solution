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
            int flag = 1;
            int k = arr[0];
            if(arr[0] != arr[n-1]){
                  cout<<"NO\n";
                  continue;
            }
            // for(int i = 1; i< n-1;i++){
            //     if(arr[i] < arr[0]){
            //         flag = 1;
            //           break;
            //     }
            //     if(i != 1 && arr[i] > arr[i-1] && arr[i] < arr[i+1]){
            //           flag = 1;
            //           break;
            //     }
            // }
          if(flag)
            cout<<"NO\n";
          else {
              cout<<"YES\n";
          }
     }
}