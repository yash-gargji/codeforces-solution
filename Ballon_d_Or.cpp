#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         int count = 0;

         for(int i = 0;i<n;i++){
              int num;
              cin>>num;

              if(num == 2){
                 count++;
              }
         }
         if(count % 8  == 0){
             cout<<"YES\n";
         }
         else {
             cout<<"NO\n";
         }
    }
}