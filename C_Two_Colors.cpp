#include<bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>arr(m),suff(m);

        for(int i = 0;i<m;i++){
           cin>>arr[i];
           if(arr[i] == n)
              arr[i]--;
        }
        sort(arr.begin(),arr.end());
        suff[m-1] = arr[m-1];
        for(int i = m-2;i >= 0;i--){
           suff[i] += arr[i] + suff[i+1];
        }
        long long ans = 0;

        for(int i = 0;i<m-1;i++){
            int l = i + 1;
            int r = m-1;

            while(l <= r){
               int mid = (l + r)/2;

               if(arr[i] + arr[mid] >= n){
                   r = mid - 1;
               }
               else{
                l = mid + 1;
               }
            }
            r++;
            if(r != m){
               int num = m - r;
               ans += 2*(num * arr[i] + suff[r] - num*(n-1));
            }
        }
       cout<<ans<<endl;
 
    }
}