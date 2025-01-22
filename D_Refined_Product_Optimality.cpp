#include<bits/stdc++.h>
using namespace std;
#define int long long

int mod = 998244353;

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int q;
        cin>>q;

        int a[n],b[n],val[n];

        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        long long ans = 1;
        for(int i = 0;i<n;i++){
            cin>>b[i];
            val[i] = min(a[i],b[i]);
            ans = (ans * val[i]) % mod;
        }
        
        cout<<ans<<" ";

        while(q--){
            int op,ind;
            cin>>op>>ind;
            int prev = val[ind-1];
            if(op == 1)
              a[ind-1]++;
            else
             b[ind-1]++;
            val[ind-1] = min(a[ind-1],b[ind-1]);
            
            if(val[ind-1] != prev){
               ans = (ans * val[ind-1] / prev) % mod;
            }
          cout<<ans<<" ";
        }
      cout<<endl;
    }
}