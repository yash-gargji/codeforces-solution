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
       int seg = -1;
       int sum = 0;
       int count = 0;
       int ans = 0;
       map<int,int>mp;
       mp[0]++;
       
       for(int i = 0;i<n;i++){
           if(s[i] == '1')
             count++;
            else
              count--;
           ans += ((i+1)*i - seg);
           mp[count]++;
           seg += i;
       } 
       int tc = mp.begin()->second;
       sum = mp.begin()->second*mp.begin()->first;

       for(auto it : mp){
          if(it.first == mp.begin()->first)
            continue;
          ans += it.second*(tc*it.first - sum);
          sum += it.first*it.second;
          tc += it.second;
       }
      cout<<ans/2<<endl;
    }
}