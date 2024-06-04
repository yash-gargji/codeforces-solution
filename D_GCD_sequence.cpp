#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
          int n;
          cin>>n;
          int arr[n];
          vector<int>b(n-1);

          for(int i = 0;i<n;i++){
             cin>>arr[i];
          }
          int d = 0;

          for(int i = 0;i<n-1;i++){
             b[i] = __gcd(arr[i],arr[i+1]);
          }
          for(int i = 1;i<n-1;i++){
              if(b[i] < b[i-1])
                 d++;
          } 
          if(d == 0){
             cout<<"YES\n";
             continue;
          } 
          else if(d > 3){
              cout<<"NO\n";
              continue;
          }
          if(b[1] < b[0] && d-1 == 0){
             cout<<"YES\n";
             continue;
          }
          if(b[n-2] < b[n-3] && d - 1 == 0){
             cout<<"YES\n";
             continue;
          }
          int ans = 0;
          for(int i = 1;i<n-1;i++){
              int k = d;

              if(b[i] < b[i-1]){
                 k--;
              }
              if(i-2 >= 0 && b[i-1] < b[i-2]){
                  k--;
              }
              if(i < n-2){
               if(b[i+1] < b[i]){
                   k--;
               }
              }
            int num = __gcd(arr[i-1],arr[i+1]);
            if(i-2 >= 0 && num < b[i-2]){
                  k++;
            }
            if(i < n-2 && num > b[i+1]){
                k++;
            }
            if(k == 0){
               ans = 1;
               break;
            }
          }
        if(ans == 1){
              cout<<"YES\n";
        }
        else{
             cout<<"NO\n";
        }
     }
}