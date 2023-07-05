#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin>>s;
     int p = stoi(s);
     if(p<= 74 && p> 47){
        cout<<74;
        return 0;
     }
      if(s.size()%2 == 1){
    
    for(int i = 0;i<s.size()/2 +1;i++){
        cout<<4;
   }
     for(int i = s.size()/2 +1;i<s.size() +1;i++){
        cout<<7;

   }
    return 0;
 }
 int a = 0,b = 0;
     int f1 = s.size(),f2 = s.size(),f3 = 0;
         for(int i = 0;i<s.size();i++){
               if(s[i] > '7' && f1 == s.size()){
                  f3 = 1;
                  break;
               }
               else if(s[i] == '7'){
                b++;
               }
               else if(s[i] == '4'){
                a++;
               }
               else if(s[i]< '7' && s[i] > '4'){
                f1 = min(f1,i);
                   break;
               }
               else if(s[i] <'4'){
                   f2 = i;
                   break;
               }
         }
         int n = s.size();
         
         if(f3 == 1  ){
          for(int i = 0;i<s.size() +2;i++){
            if(i >= s.size()/2 +1){
              cout<<7;
            }
            else{
              cout<<4;
             }
           }
      }
         else if(a == b  && b ==  s.size()/2){
             cout<<s;
         }
         else if( a>n/2){
           for(int i = 0;i<s.size() ;i++){
            if(i >= s.size()){
              cout<<7;
            }
            else{
              cout<<4;
             }
           }
      }
         
         else if(min(f1,f2) == f1 &&  f1 < s.size()/2 ){
                  for(int i = 0;i<f1;i++){
                    cout<<s[i];
                  }
                  cout<<7;
                  a = s.size()/2 - a;
                  while(a--){
                    cout<<4;
                  }
                  b = b+1;
                  b = n/2  - b;
                    while(b--){
                    cout<<7;
                  }
         } 
         else if(f2 != n){
              for(int i = 0;i<f2;i++){
                    cout<<s[i];
                  }
                  cout<<4;
                  a = s.size()/2 - a-1;
                  while(a--){
                    cout<<4;
                  }
                  
                  b = n/2  - b;
                    while(b--){
                    cout<<7;
                  }
         }
         else{
          a = 0, b =0;
         int k = n;
          for(int i = 0;i<s.size()/2;i++){
            k = i;
            if(s[i] == '7'){
                b++;
            }
            else{
              s[i] == '7';

              b++;
              a = 1;
              break;
            }
          }
          if(a == 0 && b>= s.size()/2){
                   for(int i = 0;i<s.size() +2;i++){
            if(i >= s.size() +1){
              cout<<7;
            }
            else{
              cout<<4;
             }
           }
          }
          else {
            a = a-1;
              for(int i = 0;i<=k;i++){
                    cout<<s[i];
                  }
                  
                  a = s.size()/2 - a;
                  while(a--){
                    cout<<4;
                  }
                  
                  b = n/2  - b;
                    while(b--){
                    cout<<7;
                  }
          }
         }
}