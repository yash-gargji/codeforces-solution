#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int ans = 0;
    int prev = 0;
    int flag = 0;

    for(int i = 0;i<n;i++){
        if(arr[i] == 0){
           int count = 1;
           for(int j = i+1;j<n;j++){
               if(arr[i] == arr[j]){
                  i = j;
                  count++;
               }
               else{
                 break;
               }
           }
          count -= flag;
          flag = 0;
          prev = count;
        }
        else {
            ans++;
           int count = 0;
           int two = 0;
           for(int j = i;j<n;j++){
              if(arr[j] == 0){
                  break;
              }
              i = j;
              count++;
              if(arr[j] == 2)
              
              two = 1;
           }
           ans += max(prev-1,0);
          if(two == 0 && prev == 0){
             flag = 1;
          }
          else if(two == 1){
              flag = 1;
          }
          prev = 0;
        }
    }
  cout<<ans + prev<<endl;
}