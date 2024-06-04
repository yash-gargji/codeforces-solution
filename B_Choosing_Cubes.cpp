#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
          int n,f,k;
          cin>>n>>f>>k;
          int arr[n];
          
          for(int i = 0;i<n;i++){
             cin>>arr[i];
          }
          int num = arr[f-1];
          sort(arr,arr+n);

          reverse(arr,arr+n);

          int first = -1;
          int last = -1;

          for(int i = 0;i<n;i++){
               if(arr[i] == num){
                   last = i+1;
                   if(first == -1)
                     first = i+1;
               }
          }
       if(last <= k){
           cout<<"YES\n";
       }
       else if(first > k){
          cout<<"NO\n";
       }
       else cout<<"MAYBE\n";
     }
}