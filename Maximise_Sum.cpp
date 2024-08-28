#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
         int arr[n];
         int sum = 0;
         int count = 0;
         long long ans = 0;
         int mi = INT_MAX;
         int ma = INT_MIN;
         for(int i = 0;i<n;i++){
             cin>>arr[i];
             if(arr[i] >= 0){
                mi = min(mi,arr[i]);
                ans += arr[i];
             }
             else{
                count++;
                ans += abs(arr[i]);
                ma = max(ma,arr[i]);
             }
         }
        if(count % 2 == 0){
             cout<<ans<<endl;
             continue;
        }
        else{
           if(abs(ma) >= mi){
               ans -= 2*mi;
           }
           else{
              ans += 2*ma;
           }
        }
      cout<<ans<<endl;
    }
}