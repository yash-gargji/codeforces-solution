#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    int t;
    cin >> t;
    
     while(t--){
          ll r;
          cin>>r;
          ll ans = 4;

          for(ll i = 1;i <= r;i++){
               ll l = 1;
               ll h = r;
               ll low = 1;
              
              while(l <= h){
                  ll mid = (l+h)/2;
                  ll low = 1;
                  if(i*i + mid*mid < r*r){
                     low = mid;
                     l = mid + 1;
                  }
                  else {
                     h = mid - 1;
                  }
              }
             low = l;
             l = 1;
             h = r;
             while(l <= h){
                ll mid = (l + h)/2;

                if(mid*mid + i*i  >= (r+1)*(r+1)){
                    h = mid - 1;
                }
                else 
                 l = mid + 1;
             }
             ll  high = h;
             ans += (high - low + 1)*4;
          }
        cout<<ans<<endl;
     }

    return 0;
}
