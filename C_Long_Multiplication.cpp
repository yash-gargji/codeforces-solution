#include<bits/stdc++.h>
using namespace std;

 void solve(){
       string s, k;
       cin >> s >> k;
        int ind = 0;

        for(int i = 0;i<s.size();i++){
               if(s[i] != k[i]){
                  break;
               }
               ind++;
        }
          if(ind != s.size() && s[ind] < k[ind]){
                 swap(s[ind],k[ind]);
          }
          ind++;

          for(int i  = ind ;i<s.size();i++){
                 if(s[i] >= k[i]){
                      swap(s[i],k[i]);
                 }
          }
          cout<<s<<endl;
          cout<<k<<endl;

 }
int main(){
     int t;
     cin>>t;
     
     while(t--){
        solve();
     }
}