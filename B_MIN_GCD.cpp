#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         int arr[n];

         for(int i = 0;i<n;i++){
            cin>>arr[i];
         }
         int gcd = 0;
         sort(arr,arr+n);

         for(int i = 1;i<n;i++){
            if(arr[i] % arr[0] == 0){
               if(gcd == 0)
                 gcd = arr[i];
               else 
                 gcd = __gcd(gcd,arr[i]);
            }
         }

         if(arr[0] == gcd){
             cout<<"Yes\n";
         }
         else{
            cout<<"No\n";
         }

         
    }
}