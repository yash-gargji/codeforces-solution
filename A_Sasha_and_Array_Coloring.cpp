#include<bits/stdc++.h>
using namespace std ;

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
          sort(arr,arr+n);
          long long int sum = 0;
          for(int i =  0;i<n/2;i++){
           sum = sum + abs(arr[i] - arr[n-1-i]);
          }
          cout<<sum<<endl;
    }
}