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
        int p = 0;
        int sp = 0;
        
        for(int i = 0;i<n;i++){
            if(s[i] == 's' && p > 0)
               flag = 1;
            if(s[i] == 's')
               sp +=1;
            else if(s[i] == 'p'){
                p++;
            }
        }
        if(flag){
           cout<<"NO\n";
        }
        else if(sp == 0 || p == 0){
           cout<<"YES\n";
        }
        else {
          int num = 0;
          if(s[0] == '.' && s[n-1] == '.'){
             cout<<"NO\n";
             continue;
          }
          p = 0,sp = 0;
        
         for(int i = 1;i<n-1;i++){
             if(s[i] == 's'){
                sp ++;
             }
             else if(s[i] == 'p'){
                p++;
             }
         }
         if(sp && p){
         cout<<"NO\n";
         }
         else{
             cout<<"YES\n";
         }
        }
    }
}