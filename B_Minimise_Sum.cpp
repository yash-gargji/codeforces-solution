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

         for(int i = 0;i<n;i++){
             cin>>arr[i];
         }
         int ans = 1e18;
         vector<int>pre(n);
         int sum = 0;
         int mi = 0;
         
         for(int i = 0;i<n;i++){
            if(i != 0){
                if(mi == i-1){
                   ans = min(ans,arr[i-1] + arr[i] + pre[mi]);
                }
                else {
                    ans = min(ans,(i - mi)*arr[mi] + pre[mi]);
                }
             }
             if(arr[i] < arr[mi]){
                mi = i;
             }
             pre[i] = sum;
             sum += arr[mi];
         }
        ans = min(ans,sum);

        cout<<ans<<endl;
    }
}