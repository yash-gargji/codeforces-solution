#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int ans = 0;
        int flag = 0;
        for(int i = 0;i<n;i++){
            cin>>arr[i];
            if(arr[i] < 0){
                  flag = 1;
                  ans = arr[i];
            }
        }
        if(flag == 1){
            cout<<ans<<endl;
        }
        else{
            cout<<(*max_element(arr,arr+n))<<endl;
        }
   }
}