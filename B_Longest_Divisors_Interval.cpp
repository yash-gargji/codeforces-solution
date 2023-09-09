#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     while(t--){
        long long int n;
        cin>>n;
          int count = 1;
          int ans = 1;
          if(n%2 == 1){
            cout<<1<<endl;
            continue;
          }
          for(int i = 2;i<= 100 ;i++){
                 if(n%i == 0){
                     count++;
                     ans = max(ans,count);
                 } 
                 else{
                    count = 0;
                 }
          }
          cout<<ans<<endl;
     }
}