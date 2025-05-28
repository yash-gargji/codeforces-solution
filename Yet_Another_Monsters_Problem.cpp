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
        sort(arr,arr+n);
        int ans = min(n,arr[n-1]);

        for(int i = n-1;i > 0;i--){
            ans = min(ans,n - i + arr[i-1]);
        }

        cout<<ans<<endl;
        
    }
}