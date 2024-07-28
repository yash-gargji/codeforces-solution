#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int ans = 0;
        int arr[n];

        for(int i = 0;i<n;i++){
             cin>>arr[i];
        }
        for(int i = 0;i<n;i++){
             if(i%2 == 0 && (n - i - 1) % 2 == 0){
                 ans = max(ans,arr[i]);
             }
        }
       cout<<ans<<endl;
    }
}