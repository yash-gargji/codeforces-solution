#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;

        int num = n;
        int len = n;
        long long ans = 0;
        int prev = 1;
        while(len >= k){
            if(len % 2){
                ans += prev * (n+1)/2;
            }
             prev = prev*2;
            len = len/2;
        }
        
         cout<<ans<<endl;
    }
}