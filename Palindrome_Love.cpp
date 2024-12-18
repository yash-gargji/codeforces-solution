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
        int flag = 2;
        if(n == 2 && s[0] != s[n-1]){
          cout<<"-1\n";
          continue;
        }
        if(s[0] == s[n-1])
            for(int i = 1;i<n/2;i++){
            if(s[i] != s[n-i-1]){
                flag = 1;
                break;
            }
           }  
         else{
            flag = 0;
         }
        if(flag == 0){
           int f1 = 1;
           int f2 = 1;
           for(int i = 0;i<n/2;i++){
               if(s[i] != s[n - i - 2]){
                   f1 = 0;
               }
           }
           for(int i = 1;i<n/2 + n%2;i++){
               if(s[i] != s[n - i]){
                   f2 = 0;
               }
           }
           if(f1 == 0 || f2 == 0){
             cout<<"1\n";
           }
           else{
             cout<<"-1\n";
           }
        }
        else if(flag == 1){
             cout<<"1\n";
        }
        else
         cout<<"0\n";
        
     }
}