#include<bits/stdc++.h>
using namespace std;

int main(){
   long long int a,b,c,d;
     cin>>a>>b>>c>>d;

       int ans = - 1;
       int low = 0;
       int high = 1e9;

      while(low <= high){
         long long int t = (low + high) / 2;

         if(a + b*t >= c + d*t) {
            ans = t;
            high = t-1;
         }
         else{
             low = t + 1;
         }
      }
    cout<<ans<<endl;
}