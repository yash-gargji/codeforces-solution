#include<bits/stdc++.h>
using namespace std;

int main(){
   int t;
   cin>>t;  
   while(t--){
       int n;
       cin>>n;
       vector<int>arr(n);

       for(int i = 0;i<n;i++){
        cin>>arr[i];
       }

       long long int ans = 0;

       for(int i = 1;i<n-1;i++){
          if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
             int a =0,b = 00 ;

             for(int j = i-1;j >= 0;j--){
                if(arr[j] < arr[j+1]){
                     a++;
                }
                else 
                  break;
             }
             for(int j = i+1;j < n;j++){
                if(arr[j] < arr[j-1]){
                    b++;
                }
                else 
                  break;
             }
             ans += 1ll*a*b;
          }
       }
       cout<<ans<<endl;
   }
}