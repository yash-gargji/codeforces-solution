#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
       int n;
       cin>>n;
       int arr[n];

       long long int sum = 0;
       
       for(int i = 0;i<n;i++){
           cin>>arr[i];
           sum += arr[i];
       }
       
       sort(arr,arr+n);
       int q;
       cin>>q;

       while(q--){
          int x,y;
          cin>>x>>y;
          
           auto ind = lower_bound(arr,arr+n,x) - arr;
           if(ind == n)
             ind--;
            long long temp = sum - arr[ind];

          long long ans = max(x - arr[ind],0) + max(y - temp,0ll);
          ind--;
          if(ind >= 0){
             temp = sum - arr[ind];
             ans = min(ans,max(x - arr[ind],0) + max(y - temp,0ll));
             
          }
          
          cout<<ans<<endl;
       }
       
    }
}