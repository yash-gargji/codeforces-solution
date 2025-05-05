#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main() {
    int t;
    cin >> t;

    while (t--) {
       int n,k;
       cin>>n>>k;
       int arr[n];

       for(int i = 0;i<n;i++){
          cin>>arr[i];
       }
       int ma = 0;
       vector<int>dp(n,0);

       for(int i = 0;i<n;i++){
           if(i + k < n)
             dp[i+k] = max(dp[i+k],ma + arr[i]);
           if(i + k + 1 < n){
              dp[i+k+1] = max(dp[i+k+1],max(ma,dp[i]) + arr[i]);
           }
           ma = max(ma,dp[i]);
       }
       cout<<ma<<endl;
    }
}
