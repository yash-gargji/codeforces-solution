#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         
         int a[n];
         int b[n];

         for(int i = 0;i<n;i++){
           cin>>a[i];
         }
         for(int i = 0;i<n;i++){
             cin>>b[i];
         }
         int num = -1;
         int flag = 0;
          int ma = INT_MAX;
         
         for(int i = 0;i<n;i++){
             if(a[i] < b[i]){
                if(num == -1){
                   num = abs(a[i] - b[i]);
                }
                else {
                     flag = 1;
                }
             }
             else if(a[i] >= b[i]){
                  ma = min(ma,a[i] - b[i]);
             }
         }
       if(ma < num){
         flag = 1;
       }
       if(flag){
          cout<<"NO\n";
       }
       else{
           cout<<"YES\n";
       }
    }
}