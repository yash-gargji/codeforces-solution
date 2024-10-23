#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
     int t;
     cin>>t;
     while(t--){
         int n,k;
         cin>>n>>k;
         int arr[n];
         int sum = 0;
         for(int i = 0;i<n;i++){
             cin>>arr[i];
             sum += arr[i];
         }
         sort(arr,arr+n);
         int last = 1;
         
         for(int i = 1;i<=n;i++){
             if(((sum + k)/i)*i >= sum && (sum + k)/i >= arr[n-1])
                last = i;
         }
         cout<<last<<endl;
     }
}