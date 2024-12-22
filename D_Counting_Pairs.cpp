#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        long long ans = 0;
        int arr[n];
        long long sum = 0;

        for(int i = 0;i<n;i++){
           cin>>arr[i];
           sum += arr[i];
        }
        sort(arr,arr+n);

        for(int i = 0;i<n;i++){
           ans += (lower_bound(arr+i+1,arr+n,sum - arr[i] - k) - upper_bound(arr+1+i,arr+n,sum - arr[i] - m));
        }
        cout<<abs(ans)<<endl;
    }
}