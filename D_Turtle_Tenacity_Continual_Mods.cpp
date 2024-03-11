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

         if(n == 1) cout<<"YES\n";
         else if(arr[0] != arr[1]) {
            cout<<"YES\n";
         }
         else{
            int flag = 0;
            for(int i = 1;i<n;i++){
                if(arr[i] % arr[0] > 0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag) cout<<"YES\n";
            else{
                cout<<"NO\n";
            }
         }
    }
} 