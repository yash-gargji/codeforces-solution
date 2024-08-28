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
         int l = 0;
         int r = n-1;
         for(int i = 0;i<n;i++){
             if(arr[i] <= 0){
                 l++;
             }
             else{
                break;
             }
         }
         for(int i = n-1;i >= 0;i--){
             if(arr[i] <= 0){
                 r--;
             }
             else{
                break;
             }
         }
         int count = 0;
         for(int i = l;i<= r;i++){
              if(arr[i] < 0){
                count++;
              }
         }
        cout<<count<<endl;
    }
}