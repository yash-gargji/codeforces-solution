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
          int even  = 0;
          int odd = 0;
          for(int i = 0;i<n;i++){
              int num;
              cin>>num;
              if(num%2 == 1){
                odd++;
              }
              else{
                even++;
              }
          }
          if(odd%2 == 1){
              cout<<"NO\n";
          }
          else{
            cout<<"YES\n";
          }
      }
}