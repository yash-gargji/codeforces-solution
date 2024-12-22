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
        sort(arr, arr + n);
        int ans = 0;

        int count = 0;
        
        for(int i = 0;i<n;i++){
           if(arr[i] > count){
               ans += arr[i] - count;
           }
            count++;
        }
      cout<<ans<<endl;
    }
}