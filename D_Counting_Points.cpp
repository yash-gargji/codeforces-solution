#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin >> t;
    
    while (t--) {
         int n,m;
         cin>>n>>m;

         vector<int>c(n),r(n);

         map<int,int>mp;

         for(int i  = 0;i<n;i++){
           cin>>c[i];
         }
         for(int i  = 0;i<n;i++){
           cin>>r[i];
         }

         long long ans = 0;

         for(int i = 0;i<n;i++){
             int l = c[i] - r[i];
             int re = c[i] + r[i];

             for(int j = l; j<= re;j++){
                 int low = 0;
                 int high = 1e8;
                 int num = 0;

                 while(low <= high){
                     int mid = (low + high) / 2;

                     if((j - c[i]) * (j - c[i]) + mid * mid <= r[i]*r[i]){
                         num = mid;
                         low = mid + 1;
                     }
                     else{
                        high = mid - 1;
                     }
                 }
                 num++;
                 ans += max(0ll,2*num-1 - mp[j]);
                 mp[j] = max(mp[j],2*num - 1);
             }
         }
        cout<<ans<<endl;
    }
}
