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
       int ans = 0;

       for(int i  =0;i<n;i++){
          cin>>arr[i];
       }
       sort(arr,arr+n);

       for(int i = 0;i<n;i++){
           for(int j = i+1;j<n;j++){
               int ind1 = n;
               int ind2 = j;
               
               int l = j+1,r = n-1;

               while(l <= r){
                  int mid = (l + r)/2;
                  if(arr[i] + arr[j] + arr[mid] > arr[n-1]){
                     ind1 = mid;
                     r = mid -1;
                  }
                  else{
                     l = mid + 1;
                  }
               }
               l = j+1,r = n-1;
               while(l <= r){
                  int mid = (l + r)/2;
                  if(arr[i] + arr[j] > arr[mid]){
                     ind2 = mid;
                     l = mid +1;
                  }
                  else{
                      r = mid - 1;
                  }
               }
               ans += max(0ll,ind2 - ind1 + 1);
           }
       }
       cout<<ans<<endl;
    }
}