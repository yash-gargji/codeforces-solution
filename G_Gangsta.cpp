#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
       int n;
       cin>>n;
       string s;
       cin>>s;
       int ans = 0,sum = 0,count = 0,tc = 0;
       map<int,int>mp;
       mp[0]++;
       
       for(int i = 0;i<n;i++){
           if(s[i] == '1')
             count++;
            else
              count--;
           ans += (i+2)*(i+1)/2;
           mp[count]++;
       } 
       
       for(auto it : mp){
          int val = it.first, ct = it.second;
          if(val != mp.begin()->first){
             ans += ct*(tc*val - sum);
          }
          sum += val*ct;
          tc += ct;
       }
      cout<<ans/2<<endl;
    }
}