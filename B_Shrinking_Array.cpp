#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
       int n;
       cin>>n;

       int ans = -1;

       int arr[n];

       for(int i  =0;i<n;i++){
          cin>>arr[i];
       }
       for(int i = 0;i<n-1;i++){
           if(abs(arr[i] - arr[i+1]) <= 1){
              ans = 0;
           }
       }
       if(ans == 0){
          cout<<ans<<endl;
          continue;
       }
       for(int i = 1;i<n-1;i++){
           if(arr[i] > arr[i+1] && arr[i] > arr[i-1]){
              ans = 1;
           }
           if(arr[i] < arr[i+1] && arr[i] < arr[i-1]){
              ans = 1;
           }
       }
       
          cout<<ans<<endl;
    }
}