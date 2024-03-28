#include<bits/stdc++.h>
using namespace std;
    
int main(){
     int t;
     cin>>t;

     while(t--){
        int n;
        cin>>n;

        int arr[n];
        int ans = -1e9;
        int sum = 0;
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }

        for(int i = 0;i<n;i++){
              if(i != 0 && abs(arr[i-1])%2 == abs(arr[i]) %2){
                sum = arr[i];
              }
              else 
               sum += arr[i];
             ans = max(ans,sum);
             if(sum <= 0) 
               sum = 0;
        }
       cout<<ans<<endl;
     }
} 