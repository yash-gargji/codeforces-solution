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
        if(n >= 3 || abs(arr[0] - arr[1]) <= 1){
              cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
        
    }
}