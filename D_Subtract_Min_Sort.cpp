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
        }
        for(int i = 0;i<n;i++){
           if(i != 0 ){
              arr[i] = (arr[i] - arr[i-1]);
           }
           if(i != n-1 && arr[i] > arr[i+1]){
              flag = 0;
              break;
           }
        }
        if(flag){
          cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}