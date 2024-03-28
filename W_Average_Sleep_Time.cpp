#include<bits/stdc++.h>
using namespace std;
    
int main(){
     int n,k;
     cin>>n>>k;
      double ans = 0;
      double arr[n];
      double window = 0;
     for(int i = 0;i<n;i++){
           cin>>arr[i];
           if(i <k){
            window += arr[i];
           }
     }
    ans += window;

    for(int i = k;i<n;i++){
        window = window + arr[i] - arr[i-k];
        ans += window;
    }
    cout << fixed << setprecision(8) << ans/(n - k + 1);
} 