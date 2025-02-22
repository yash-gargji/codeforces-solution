#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
        int n;
        cin>>n;
        int arr[n];
        int ans = 0;

        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        for(int i = 0;i<n;i++){
             int num = arr[i];
            if(i == 1){
               num = max(0,num - arr[i-1]);
            }
            if(i == n-2){
               num = max(0,num - arr[i+1]);
            }
            ans = max(ans,num);
              
        }
        cout<<ans<<endl;
     }
}