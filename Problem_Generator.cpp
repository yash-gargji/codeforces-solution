#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
          int n,m;
          cin>>n>>m;
          string s;
          cin>>s;
          vector<int>v(7);

          for(int i = 0;i<n;i++){
              if(s[i] - 'A' <= 6){
                  v[s[i] - 'A']++;
              }
          }
          int ans = 0;
          for(int i = 0;i<7;i++){
                if(v[i] <= m){
                     ans += -v[i] +m;
                }
          }
         cout<<ans<<endl;
     }
}