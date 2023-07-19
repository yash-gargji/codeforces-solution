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
         long long int s1 = 0;
         long long int s2 = 0;
          
         for(int i = 0;i<n;i++){
            cin>>arr[i];
             
         }  
         for(int i = 0;i<n;i++){
            if(i%2 == 0 && arr[i] >= 0){
                   s1 = s1 + arr[i]; 
            }
            else if(i%2 == 1 && arr[i] >= 0){
                    s2 = s2 + arr[i];
            }
         }
         sort(arr,arr+n);
         if(max(s1,s2) <= 0 ){
            cout<<arr[n-1]<<endl;
         }
         else{
            cout<<max(s1,s2)<<endl;
         }
      }
     return 0;
}