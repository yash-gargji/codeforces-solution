#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int flag = 1;
        
        for(int i = 0;i<n;i++){
            cin>>arr[i];
            if(arr[i] != 0){
               flag = 0;
            }
        }
        
        if(flag){
          cout<<0<<endl;
        }
        else{
            int count = 0;
          for(int i = 0;i<n;i++){
             if(arr[i] == 0){
                continue;
             }
             count++;
             for(int j = i;j<n;j++){
                 if(arr[j] != 0){
                   i = j;
                 }
                 else{
                   break;
                 }
             }
          }
          if(count > 1){
                cout<<"2 \n";
             }
             else {
               cout<<"1 \n";
             }
        }
    }
}