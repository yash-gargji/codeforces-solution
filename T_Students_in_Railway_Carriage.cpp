#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
     int a,b;
     cin>>a>>b;
     string s;
     cin>>s;
      int count = 0;
      int ans = 0;
      for(int i = 0;i<n;i++){
        if(s[i] == '.'){
            count = 1;
            for(int j = i+1;j<n;j++){
                if(s[i] != s[j]){
                    break;
                }
                else{
                   count++;
                   i = j;
                }
            }
           int ma = count/2 + count%2;
           int mi = count/2;

           if(a >= b){
            if(ma >= a){
               ans += a;
               a = 0;
            }
            else{
                ans += ma;
                a = a- ma;
            }
             if(mi >= b){
               ans += b;
               b = 0;
            }
            else{
                ans += mi;
                 b = b - mi;
            }
           }
           else{
            if(mi >= a){
               ans += a;
               a = 0;
            }
            else{
                ans += mi;
                a = a- mi;
            }
             if(ma >= b){
               ans += b;
               b = 0;
            }
            else{
                ans += ma;
                 b = b - ma;
            }
           }
           count = 0;
        }
      }
      cout<<ans;
}