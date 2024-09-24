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
       int sum = 0;
       for(int i = 0;i<n;i++){ 
           cin>>arr[i];
           sum += arr[i];
       }
       sort(arr,arr+n);
       if(n <= 2){
         cout<<"-1\n";
         continue;
       }
       int l = 0,r = 1e12,ans = 0;
       while(l <= r){
          int mid = (l + r )/2;
          double k = sum + mid;
          k = k/(2 * n);
          int count = 0;
          arr[n-1] += mid;
          for(int i = 0;i<n;i++){
              if(arr[i] < k)
                count++;
          }
          arr[n-1] -= mid;
         if(count > n/2 + 1){
             ans = mid;
              r = mid - 1;
         }
         else{
             l = mid + 1;
         }
       }
      cout<<ans<<endl;
    }
}
