#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
       int l = 2;
       int r = 999;
       int ans  = -1;
       
      while(l <= r){
        int mid = (l+r)/2;
         cout<<"? 1 "<<mid<<endl;
         int num;
         cin>>num;
         if(l == r){
            if(num == mid){
               ans = mid +1;
            }
            else{
                ans = mid;
            }
           break;
         }
         if(num == mid){
           l = mid + 1;
         }
         else{
            r = mid-1;
            ans = mid;
         }
      }
      cout<<"! "<<ans<<endl;
    }
}  