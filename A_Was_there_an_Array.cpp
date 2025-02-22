#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int arr[n-2];

        for(int i = 0;i<n-2;i++){
           cin>>arr[i];
        }
        int ans = 0;

        for(int i =  1;i<n-3;i++){
            if(arr[i] == 0 && arr[i-1] == 1 && arr[i+1] == 1){
               ans = 1;
               break;
            }
        }
    }
}