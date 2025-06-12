#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int>pre(64);

        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            int ind = 0;

            while((1ll << ind) <= num){
                  if(((1ll << ind) & num) > 0 )
                      pre[ind]++;
                   ind++;
            }
        }
        int ans = 0;
        for(int i = 0;i<63;i++){
            ans += pre[i];
            int num = 1ll << i;
            int rem = n - pre[i];
            rem = min(rem,k/num);
            k-= rem*num;
            ans += rem;
        }
      cout<<ans<<endl;
    }
}