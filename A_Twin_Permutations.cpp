
#include<bits/stdc++.h>
using namespace std;

int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
       int t;
       cin>>t;
       while(t--){
           int n;
           cin>>n;
           int arr[n];
           for(int i = 0;i<n;i++){
            
               cin>>arr[i];
              
           }
           for(int i = 0;i<n;i++){
            int num = n+1 - arr[i];
            cout<<num<<" ";
           }
           cout<<endl;
       }
    
}