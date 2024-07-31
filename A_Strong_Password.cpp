#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
          string s;
          cin>>s;
          int flag = 0;
          cout<<s[0];
          for(int i = 1;i<s.size();i++){
              if(s[i] == s[i-1] && flag == 0){
                for(int j = 0;j<26;j++){
                    if(s[i] != j + 'a'){
                       char c = 'a' + j;
                       flag = 1;
                       cout<<c;
                       break;
                    }
                 }
                
              }
             cout<<s[i];
          }
          if(flag == 0){
            for(int j = 0;j<26;j++){
                    if(s[s.size() - 1] != j + 'a'){
                       char c = 'a' + j;
                       flag = 1;
                       cout<<c;
                       break;
                    }
                 }
          }
         cout<<endl;
    }
}