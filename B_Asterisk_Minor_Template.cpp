#include<bits/stdc++.h>
using namespace std;

int  main(){
      long long t;
      cin>>t;
      
      while(t--){
           string a,b;
           cin>>a>>b;
           vector<int>v(26);
           int flag = 0;

           for(int i = 0;i<a.size();i++){
              v[a[i] -'a'] = 1;
           }
           for(int i = 0;i<a.size();i++){
              v[b[i] -'a'] &= 1;
           }
           for(int i = 0;i<26;i++){
              if(v[i] == 1){
                char c = 'a' + i;
                 cout<<"YES\n*"<<c<<"*\n";
                 flag = 1;
                 break;
              }
           }
          if(!flag)
            cout<<"NO\n";
      }
}