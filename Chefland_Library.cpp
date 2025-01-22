#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
       int n,k;
        cin>>n;
        map<int,int>m;
        long long ans = 0;

        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            m[num] = max(i+1,m[num]);
        }
        for(auto it:m){
            ans += it.second;
        }
      cout<<ans<<endl;
    }
}