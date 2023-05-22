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
        int flag = 0;
        for(int i = 0;i<n;i++){
               int diff;
               int j;
            for( j = i+1;j<n;j++){
                  diff = arr[j] - arr[i];
                  for(int k = j+1;k<n;k++){
                      if(arr[k] - arr[j] == diff){
                        flag = 1;
                        break;
                      }
                  } 
                  if(flag == 1){
                      break;
                  }
            }
            if(flag == 1){
               break;
             }
        }
        if(flag == 1){
            cout<<"No\n";
        }
        else{
            cout<<"Yes\n";
        }
    }
    return 0;
}