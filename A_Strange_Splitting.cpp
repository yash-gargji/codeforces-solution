#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
          int n;
          cin>>n;
         int arr[n];
         int f = 1;

          for(int i  =0;i<n;i++){
            cin>>arr[i];
          }
         
          for(int i = 1;i<n;i++){
              if(arr[i] != arr[i-1]){
                 f = 0;
                 break;
              }
          }
        if(f){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        string ans(n,'R');

        for(int i = 0;i<n;i++){
            set<int>st;
              for(int  j = 0;j<n;j++){
                  if(i != j){
                     st.insert(arr[j]);
                  }
              }
             if(st.size() > 1){
                 ans[i] = 'B';
                 break;
             }
        }
        cout<<ans<<endl;
     }
}