#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
     int t;
     cin>>t;
     
     while(t--){
          int n;
          cin>>n;

          map<int,int>mp,k;
          int ans = 0;

          map<int,int>f;
          int arr[n];
          int ma = 0;

          for(int i = 0;i<n;i++){
              cin>>arr[i];
              ma = max(ma,arr[i]);
          }
          ma = max(ma,2*n);
          if(ma > 4e5){
             ma = 2*n;
          }
          for(int i = 0;i<n;i++){
              mp[arr[i]]++;
              if(arr[i] > ma){
                  ans = max(ans,arr[i] + mp[arr[i]]);
              }
              else{
                  f[arr[i]]++;
              }
          }
          for(auto it = f.rbegin(); it != f.rend();it++){
              int i = it->first;
                if(i != 1)
                  mp[1] += f[i];
              for(int j = 2;j*j <= i;j++){
                  if(i % j == 0){
                     mp[j] += f[i];
                     if(i/j != j){
                        mp[i/j] += f[i];
                     }
                  }
              }
          }
          for(auto it:mp){
              ans = max(ans,it.first + it.second);
          } 
        cout<<ans<<endl;
     }
}