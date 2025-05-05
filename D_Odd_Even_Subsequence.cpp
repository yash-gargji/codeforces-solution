#include<bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
   int n,k;
   cin>>n>>k;
   int arr[n];

   for(int i = 0;i<n;i++){
      cin>>arr[i];
   }
   int l = 1,r = 1e9;
   int ans = -1;

   while(l <= r){
      int mid = (l + r)/2;
      int count = 0;
      
      for(int i = 0;i<n - !(k%2);i++){
          if(arr[i] <= mid){
             count++;
             i++;
          }
      }
      if(count >= (k+1)/2){
          ans = mid;
          r = mid - 1;
          continue;
      }
      count = 0;
      for(int i = 1;i<n - k % 2;i++){
        if(arr[i] <= mid){
           count++;
           i++;
        }
      }
      if(count >= k/2){
        ans = mid;
        r = mid - 1;
      }
      else 
        l = mid + 1;
   }
  cout<<ans<<endl;

}