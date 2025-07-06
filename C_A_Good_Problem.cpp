#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        int l,r,k;
        cin>>l>>r>>k;
        
        if(n % 2 ){
         cout<<l<<endl;
        }
        else {
          int num = 1ll;
          while (num <= l) 
            num <<= 1;
           if(num > r || num < l || n == 2){
              cout<<"-1\n";
           }
           else {
               if(n - k < 2){
                  cout<<num<<endl;
               }
               else {
                   cout<<l<<endl;
               }
           }
        }
    }
}
