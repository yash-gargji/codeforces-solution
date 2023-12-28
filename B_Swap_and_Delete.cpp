#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int one  = 0;
        int zero = 0;
        int l = s.size();
        int ans = l;
         
        for(int i = 0;i<s.size();i++){
             if(s[i] == '0'){
                 zero++;
             }
             else{
                one++;
             }
        }
        int o = 0;
        int z = 0;
      for(int i = 0;i<s.size();i++){
         if(s[i] == '0'){
            z++;
         }
         else{
            o++;
         }
          if(zero >= o && one >= z){
            ans = min(ans,l - i -1);
          } 
      }
      cout<<ans<<"\n";
    }
}