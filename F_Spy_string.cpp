#include<bits/stdc++.h>
using namespace  std;

int diff(string &s1,string &s2){
       int num = 0;

       for(int i = 0;i<s1.size();i++){
            if(s1[i] != s2[i]){
                num++;
            }
       }
      return num;
}

int main(){
      int t;
      cin>>t;

      while(t--){
           int n,m;
           cin>>n>>m;
            vector<string>v(n);
            int flag = 0;
            
            for(int i = 0;i<n;i++){
                cin>>v[i];
            }
            string s = v[0];
            for(int i =  0;i<m;i++){
                bool check = true;
                int f = 0;

                for(int j = 0;j<26;j++){
                     char c = s[i];
                     s[i] = 'a' + j;
                     for(int k = 0;k<n;k++){
                         if(diff(s,v[k]) > 1){
                             check = false;
                             break;
                         }
                     }
                    if(check == true){
                        f = 1;
                         break;
                    }
                     check = true;
                   s[i] = c;
                }
               if(f){
                 flag = 1;
                 break;
               }
            }
          if(flag){
             cout<<s<<endl;
          }
          else{
              cout<<"-1\n";
          }
      }
}