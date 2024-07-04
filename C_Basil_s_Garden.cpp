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
        long long int ans = arr[n-1];

        for(int i = n-2;i >= 0;i--){
            if(arr[i] > ans){
                 ans = arr[i];
            }
            else{
                ans++;
            }
        }
       cout<<ans<<endl;
    }
}