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

        int mid = n/2 + n%2;
        int count = 1;
         for(int i =mid;i<n;i++){
             if(arr[i] == arr[i-1]){
                count++;
             }
             else {
                break;
             }
         }
        cout<<count<<endl;
    }
}