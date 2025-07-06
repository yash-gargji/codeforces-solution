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
         long long num = 1;
         int prev = arr[0];

         for(int i = 0;i<n;i++){
             if(arr[i] % prev == 0){
                prev = arr[i];
                continue;
             }
             int temp = prev / num;
             if(arr[i] % temp == 0){
                prev = arr[i];
                continue;
             }
             num = num * (temp / __gcd(temp,arr[i]));
             prev = arr[i];
         }
         cout<<num<<endl;
    }
}