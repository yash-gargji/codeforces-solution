#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
       string s;
       cin>>s;
       
       int l = -1,r = -1;
       string temp;
       
       for(int i = 0;i<s.size();i++){
           if(s[i] == '1' && l == -1){
              l = i;
              temp = s.substr(i,s.size() - i);
           }
           else if(s[i] == '0' && r == -1 && l != -1){
               r = i;
           }
       }
       if(l == -1){
          cout<<"1 1 1 1\n";
       }
       else if(r == -1){
         cout<<"1 1 1 "<<s.size()<<endl;
       }
       else{
          int w = s.size() - r;
          int x,y;
          string ans = temp;
          
          for(int i = 0;i<s.size() - w + 1;i++){
              int p = i + w - 1;
              string k = temp;
              int ind = k.size() - 1;
              while(p >= i){
                 if((s[p] == '0' && k[ind] == '0') || (s[p] == '1' && k[ind] == '1')){
                     k[ind] = '0';
                 }
                 else{
                    k[ind] = '1';
                 }
                 p--;
                 ind--;
              }
             if(k >= ans){
                ans = k;
                x = i + 1;
                y = i + w;
             }
          }
         cout<<"1 "<<s.size()<<" "<<x<<" "<<y<<endl;
       }
       
    }
}