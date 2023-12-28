#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string a;
        a = a + s[0];
         string b;

         for(int i = 1;i<s.size();i++){
              if(s[i] != '0'){
                   b = b + s[i];
                   for(int j = i+1;j<s.size();j++){
                       b = b + s[j];
                   }
                    break;
              }
              else{
                 a += '0';
              }
         }
          if(a == b || a.size() > b.size()){
             cout<<"-1\n";
          }
          else if(a.size() == b.size() && a > b){
             cout<<"-1\n";
          }
          else{
              cout<<a<<" "<<b<<endl;
          }
    }
}