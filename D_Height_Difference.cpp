#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
        long long int min = 1;
         
        for(int i = 1;i<n;i++){
              if(arr[i] == arr[i-1]){
                 min++;
              }
              else{
                break;
              }
        }
          if(min == n){
              cout<<min*(min-1)<<endl;
              continue;
          }
          long long int max = 1;

        for(int i = n-2;i>= 0;i--){
             if(arr[i+1] == arr[i]){
               max++;
             }
             else{
                break;
             }
        }
        cout<<2*max*min<<endl;
    }
}