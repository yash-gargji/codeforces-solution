#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         int arr[n];

         for(int i = 0;i<n;i++){
             cin>>arr[i];
         }
         int mi = INT_MAX;
         int fl = 0;
         for(int i = n-1;i >= 0;i--){
             mi = min(mi,arr[i]);

             if(arr[i] > mi){
                 cout<<"YES\n2\n";
                 cout<<arr[i]<<" "<<mi<<endl;
                fl = 1;
                 break;
             }
         }
         if(fl == 0){
            cout<<"NO\n";
         }
    }
}