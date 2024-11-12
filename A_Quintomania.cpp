#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
         int n;
         cin>>n;
         int arr[n];
         int flag = 1;

         for(int i = 0;i<n;i++){
             cin>>arr[i];

             if(i != 0){
                int num = abs(arr[i] - arr[i-1]);
                if(num != 7 && num != 5)
                   flag = 0;
             }
         }
         if(!flag)
           cout<<"NO\n";
          else 
           cout<<"YES\n";
     }
}