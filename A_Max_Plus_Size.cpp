#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     while(t--){
         int n;
         cin>>n;
         int arr[n];
         int a = -1;
         int b = -1;
         for(int i = 0;i<n;i++){
            cin>>arr[i];
            if(i % 2 == 0){
              a = max(a,arr[i]);
            }
            else{
                b = max(b,arr[i]);
            }
         }
        cout<<max(a+n%2,b) + n/2<<endl;
     }
}