#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin>>n;
      int arr[n];
      long long int sum = 0;

      for(int i = 0;i<n;i++){
          cin>>arr[i];
          sum += abs(arr[i]);
      }
      if(n == 1){
         cout<<arr[0]<<endl;
         return 0;
      }
      long long ans = 0;
      for(int i = 0;i<n-1;i++){
          ans = max(ans,sum - abs(arr[i]) - abs(arr[i+1]) + abs(arr[i] - arr[i+1]));
      }
     cout<<ans<<endl;
}