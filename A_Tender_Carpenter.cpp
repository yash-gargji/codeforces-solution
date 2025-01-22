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

        for(int i = 1;i<n;i++){
            int a = min(arr[i],arr[i-1]);
            int b = max(arr[i],arr[i-1]);
            if(a + a > b){
               flag = 1;
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