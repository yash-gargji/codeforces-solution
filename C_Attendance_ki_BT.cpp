#include<bits/stdc++.h>
using namespace std;

int main(){
         int n;
         cin>>n;
        string s;
        cin>>s;
        int ans = INT_MAX;

         string a = "RARGB";
         
         for(int i = 0;i < n - 4;i++){
                 int count = 0;
                 for(int j = 0;j<5;j++){
                       if(s[i + j] >= a[j]){

                          count = count + min(s[i+j] - a[j],'Z' - s[i+j] + 1 + a[j] - 'A');
                       }
                       else{
                              count = count + min(abs( - s[i+j] + a[j] ),s[i+j] - 'A' + 1 + 'Z' - a[j]);
                       }
                 } 
                 ans = min(ans,count);
         }
         cout<<ans;
}