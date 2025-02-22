#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int mod = 998244353;
        vector<long long>arr(n),pre(n);
        long long count = 0;
        int one = 0;

        for(int i = 0;i<n;i++){
            cin>>arr[i];
            if(arr[i] == 1)
              one++;
            if(arr[i] == 2)
              count = count + one;
            pre[i] = count;
        }
        long long ans = 0;
        int x = 0;

        for(int i = n-1;i >= 0;i--){
            if(arr[i] == 3)
              x ++;
              if(arr[i] == 2){
                 ans = (ans + pre[i]*x) % mod;
                 cout<<i<<" "<<pre[i]<<endl;
              }
        }
      cout<<ans<<endl;
    }
}