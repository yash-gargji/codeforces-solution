#include <bits/stdc++.h>
using namespace std;
#define ll long long

 
int main() {
    ll t = 1;
    cin >> t;

    while (t--){
        ll x,y,z,k;
        cin>>x>>y>>z>>k;
        ll num = 0;

        for(ll i=1;i<=x;i++){
            for(ll j = 1;j<=y;j++){
                if(k%(i*j)==0){
                    ll l = k/(i*j);
                    if(l <= z){
                        num = max(num,(ll)(x-i+1)*(y-j+1)*(z-l+1));
                    }
                }
            }
        }
        cout<<num<<endl;
    }
        
    
}