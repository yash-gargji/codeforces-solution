#include <bits/stdc++.h>
using namespace std;

 
int main() {
     int t;
     cin>>t;

     while(t--){
        int n;
        cin>>n;
        int ma = INT_MAX;
        int arr[n];
        long long ans = 0;

        for(int i = 0;i<n;i++){
           cin>>arr[i];
           ma = min(ma,arr[i]);
        }
        for(int i = 0;i<n;i++){
            ans += arr[i] - ma;
        }
        cout<<ans<<endl;
     }
}
