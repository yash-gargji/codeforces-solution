#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long int n,k;
        cin>>n>>k;
        long long ans = 0;
        int arr[n];

        for(int i = 0;i<n;i++){
             cin>>arr[i];
        }
        sort(arr,arr+n);
        for(int i = n-1;i > 0 ;i -= 2){
           int diff = arr[i] - arr[i-1];
           if(diff >= k){
             ans += diff - k;
             k = 0;
           }
           else{
              k -= diff;
           }
        }
      if(n % 2 ){
         ans += arr[0];
      }
      cout<<ans<<endl;
    }
}