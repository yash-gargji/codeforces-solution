#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         int arr[n];
         int ans = INT_MAX;

         for(int i = 0;i<n;i++){
             cin>>arr[i];
         }
         for(int i = 0;i<n-1;i++){
             ans = min(ans,max(arr[i],arr[i+1]));
         }
        cout<<ans-1<<endl;
    }
}