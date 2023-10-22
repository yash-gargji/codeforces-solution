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
            long long int arr[n];
            long long int ans = 1;
             
            for(int i = 0;i<n;i++){
                   cin>>arr[i];
            }
            sort(arr,arr + n);
               arr[0] = arr[0] + 1;
              for(int i = n-1;i>= 0;i--){
                  ans = ans *arr[i];
              }
           cout<<ans<<endl;
      }
}