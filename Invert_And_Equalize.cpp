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
            int a = 0;
            int b = 0;

            for(int i = 0;i<n;i++){
                if(s[i] == '0'){
                    a ++;
                      for(int j = i+1;j<n;j++){
                          if(s[i] == s[j]){
                             i = j;
                          }
                          else 
                            break;
                      }
                }   
                else{
                       b ++;
                      for(int j = i+1;j<n;j++){
                          if(s[i] == s[j]){
                             i = j;
                          }
                          else 
                            break;
                      }
                }
            }
          cout<<min(a,b)<<endl;
      }
}