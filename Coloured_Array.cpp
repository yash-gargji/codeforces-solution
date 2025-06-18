#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(2*n+1);
         map<int,int>mp,count;
         int num = 1e18;
         int ans = 0;
        
        for(int i = 0;i<2*n;i++){
           cin>>arr[i];
        }
        for(int i = 0;i<2*n;i+= 2){
            if(arr[i] == arr[i+1]){
               if(mp.count(arr[i])){
                 ans += 2;
                 arr[i] = num;
                 arr[i+1] = num--;
               }
               else
                 mp[arr[i]] = 1;
            }
            else{
               count[arr[i]]++;
               count[arr[i+1]]++;
            }
        }
        for(int i = 0;i<2*n;i+= 2){
            if(count[arr[i]] == 1 && mp.count(arr[i]) == 0){
                ans ++;
                mp[arr[i]] = 1;
                count[arr[i+1]]--;
                arr[i+1] = arr[i];
            }
            else if(count[arr[i+1]] == 1 && mp.count(arr[i+1]) == 0){
                ans++;
                mp[arr[i+1]] = 1;
                count[arr[i]]--;
                arr[i] = arr[i+1];
            }
        }
        for(int i = 0;i<2*n;i+= 2){
            if(arr[i] == arr[i+1])
              continue;
            if(mp.count(arr[i]) == 0 && mp.count(arr[i+1]) == 0){
               if(count[arr[i]] >= count[arr[i+1]]){
                   count[arr[i]]--;
                   mp[arr[i+1]] = 1;
               }
               else {
                  count[arr[i+1]]--;
                  mp[arr[i]] = 1;
               }
                ans++;
            }
            else if(mp.count(arr[i+1]) == 0) {
                 ans++;
                 mp[arr[i+1]] = 1;
            }
            else if(mp.count(arr[i]) == 0) {
                 ans++;
                 mp[arr[i]] = 1;
            }
            else{
               ans += 2;
            }
        }
      cout<<ans<<endl;
    }
} 