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

        for(int i = n-2;i >=0;i--){
            arr[i] = arr[i] + arr[i+1] - 1;
        }
        cout<<arr[0]<<endl;
    }
}