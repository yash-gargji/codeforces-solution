#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
           int n;
           cin>>n;
            int arr[n];

            for(int i = 0;i<n;i++){
                  cin>>arr[i];
            }
            int flag = 1;
          for(int i = 1;i<n;i++)
          {
                 if(arr[i] != arr[i-1]){
                      flag = 0;
                      break;
                 }
          }
          if(flag){
              cout<<-1<<endl;
              continue;
          }
          int num = 0;
          int ans = INT_MAX;
          flag = 0;
        for(int i = 0;i<n;i++){
              if(arr[i] == arr[0]){
                  num++;
              }
              else{
                  flag = 1;
                  ans = min(ans,num);
                  num = 0;
              }
        }
          if(num > 0 && flag){
         cout<<min(ans,num)<<endl;  
       }
       else{
          cout<<-1<<endl;
       }
     }
}