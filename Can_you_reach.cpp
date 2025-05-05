#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
       int n;
       cin>>n;
       int arr[n];
        map<int,vector<int>>mp;

        long long ans = 1ll*n*(n-1)/2;
       for(int i = 0;i<n;i++){
           cin>>arr[i];
           mp[arr[i]].push_back(i);
       }
       int prev = -1;
       vector<int>v(n);

       for(int i = 0;i<n;i++){
           auto ind = lower_bound(mp[arr[i]].begin(),mp[arr[i]].end(),i) - mp[arr[i]].begin();
           ind--;
           if(ind != -1)
             prev = max(prev,mp[arr[i]][ind] + 1);
          v[i] = prev;
       }
       prev = INT_MAX;
       sort(v.begin(),v.end());
       for(int i = n-1;i >= 0;i--){
          auto ind = upper_bound(mp[arr[i]].begin(),mp[arr[i]].end(),i) - mp[arr[i]].begin();
          if(ind != mp[arr[i]].size()){
             prev = min(prev,mp[arr[i]][ind]-1);
          }
          auto it = upper_bound(v.begin(),v.end(),prev) - v.begin();
          it = n - it;
          ans -= it;
       }
      cout<<ans<<endl;
    }
}