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
          int m;
          cin>>m;
          int arr[m];
          for(int i = 0;i<m;i++){
               cin>>arr[i];
          }
          int count ;
          
          sort(arr,arr+m);
            int vacant = n - arr[m-1];
            int flag = 0;
          int ans = arr[m-1];
          for(int i = m-2;i>= 0;i--){
               ans = arr[i] - vacant;
               vacant = n - ans;
               if(vacant == n || ans <= 0){
                 flag = 1;
               }
          }
          if(flag){
            cout<<0<<endl;
          }
          else{
            cout<<ans<<endl;
          }
    }
}