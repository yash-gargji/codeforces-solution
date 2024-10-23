#include<bits/stdc++.h>
using namespace std;

int main(){
    int p = 0;
    long long  l = 1;
    long long r = 1e18;

    while(1){
      long long int num = pow(2,p);
      string s;
      cout<<num<<endl;
      cin>>s;
      if(s == "ok"){
          break;
      }
      p++;
    }
    r = pow(2,p);
    if(p != 0){
       l = pow(2,p-1);
    }
    long long int ans = r;
    cout<<l<<" "<<r<<endl;
    while(l <= r){
         long long int mid = (r - l)/2 + l;
         string s;
         cout<<mid<<endl;
         cin>>s;
         if(s == "ok"){
            ans = mid;
            r = mid - 1;
         }
         else{
           l = mid + 1;
         }
    }

    cout<<"! "<<ans<<endl;
}