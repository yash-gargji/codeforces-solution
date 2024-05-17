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
          int ans = 0;
          int parent = 1;
          int comp = 0;
          int sum = 0;

           for(int i = 1; i<n;i++){
               for(int j = i;j<n;j++){
                     i = j;
                     sum++;
                   if(arr[j] > arr[j+1] || j == n-1) {
                       comp++;
                       break;
                    }
                 }
              if(comp == parent){
                ans++;
                parent = sum;
                sum = 0;
                comp = 0;
              }
           }
           
        if(comp)
          ans++;
        cout<<ans<<endl;
     }
}