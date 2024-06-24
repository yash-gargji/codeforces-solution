#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;
      
      while(t--){
           int x1,x2,x3;
           cin>>x1>>x2>>x3;  
            int ans = 60;

            for(int i  =1;i<= 10;i++){
               ans = min(ans,abs(i  -x1) + abs(i - x2) + abs(i - x3));
            }
            cout<<ans<<endl;
      }
}