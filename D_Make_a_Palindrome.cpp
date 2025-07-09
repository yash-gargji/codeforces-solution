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
         int arr[n];
         vector<int>adj[n+1];
         int mi = INT_MAX;

         for(int i = 0;i<n;i++){
             cin>>arr[i];
             adj[arr[i]].push_back(i);
             mi = min(mi,arr[i]);
         }
         map<int,int>mp;
         int sum = 0;

         for(int i = 0;i<=n;i++){
             sum += adj[i].size();
             mp[i] = max(sum - k + 1,0ll);
         }
         
         int l = adj[mi][0],r = adj[mi][adj[mi].size()-1];
         int fl = 1;

         while(l <= r){
             if(arr[l] == arr[r]){
                l++;
                r--;
                continue;
             }
             if(arr[l] > arr[r]){
                if(mp[arr[l]] == 0){
                    fl = 0;
                    break;
                }
                mp[arr[l++]]--;
             }
              else {
                if(mp[arr[r]] == 0){
                    fl = 0;
                    break;
                }
                mp[arr[r--]]--;
             }
         }
         l = adj[mi][0],r = adj[mi][adj[mi].size()-1];

         while(l >= 0 && r < n){
               if(arr[l] == arr[r]){
                l--;
                r++;
                continue;
             }
             if(arr[l] > arr[r]){
                if(mp[arr[l]] == 0){
                    fl = 0;
                    break;
                }
                mp[arr[l--]]--;
             }
              else {
                if(mp[arr[r]] == 0){
                    fl = 0;
                    break;
                }
                mp[arr[r++]]--;
             }
         }
         while(l >= 0 ){
             if(mp[arr[l]] == 0){
                    fl = 0;
                    break;
             }
             mp[arr[l--]]--;
         }
         while(r < n){
             if(mp[arr[r]] == 0){
                    fl = 0;
                    break;
              }
              mp[arr[r++]]--;
         }
         if(fl){
            cout<<"YES\n";
         }
         else {
             cout<<"NO\n";
         }
          
    }
}