#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n,k;
         cin>>n>>k;
         map<int,int>mp;
         int ans = 0;
        
        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            mp[num]++;
        }
        for(auto &it:mp){
             if(k - it.first == it.first)
              ans += it.second/2;
              else if(it.first <= k/2){
                 ans += min(it.second,mp[k - it.first]);
              }
        }
      cout<<ans<<endl;
    }
}