#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    vector<int>fact[(int)1e5 + 1];

    for(int i = 1;i<=1e5;i++){
        map<int,int>mp;
        for(int j = 1; j*j <= i; j++ ){
           if(i % j == 0){
              mp[j]++;
              mp[i/j]++;
           }
        }
        for(auto it:mp){
            fact[i].push_back(it.first);
        }
    }

    while(t--){
        int n,q;
        cin>>n>>q;
        map<int,vector<int>>mp;

        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            mp[num].push_back(i);
        }
        while(q--){
            int k,l,r;
            cin>>k>>l>>r;
            l--;r--;
            int ans = 0;
            int ind = l;
            
            while(ind <= r){
                 int nxt = 1e9;
                 int div = 1;

                 for(auto it:fact[k]){
                   // cout<<it<<endl;
                     auto num = lower_bound(mp[it].begin(),mp[it].end(),ind);
                     if(num != mp[it].end() && *num <= r && *num < nxt){
                        nxt = *num;
                        div = it;
                     }
                 }
                 if(nxt == 1e9)
                   break;
                ans += (nxt - ind)*k;
                while(k % div == 0){
                    k /= div;
                }
                ans += k;
                 ind = nxt + 1;
            }
            ans += (r - ind + 1)*k;
            cout<<ans<<endl;
        }
    }
}