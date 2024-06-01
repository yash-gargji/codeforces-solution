#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
            int n;
           cin>>n;
           string s;
           cin>>s;

           int flag = 0;
           int ans=  1;
            char c = 'a';
            char num = '0';

            for(int i = 0;i<n;i++){
                 if(s[i] >= 'A' && s[i] <= 'Z')
                  {
                     ans = 0;
                     break;
                  }
                  if(s[i] >= 'a' && s[i] <= 'z'){
                      if(s[i] < c){
                         ans = 0;
                         break;
                      }
                      else
                       c =  s[i];
                       flag = 1;
                  }
                  else if(s[i] >= '0' && s[i] <= '9'){
                      if(flag || s[i] < num){
                         ans = 0;
                         break;
                      }
                      else
                       num = s[i];
                  }
            }
          if(ans)
            cout<<"YES\n";
          else 
        cout<<"NO\n";
     }
}