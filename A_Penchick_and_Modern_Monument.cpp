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
         int ans = n;
        for(int i = 0;i<n;i++){
           int count = 0;
           for(int j = i;j<n;j++){
              if(arr[i] == arr[j]){
                  count++;
                  i = j;
              }
              else{
                 break;
              }
           }
          ans = min(ans,n - count);
        }
      cout<<ans<<endl;
    }
}   