#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
       int a,x,y;
       cin>>a>>x>>y;

       if(max(x,y) < a || min(x,y) > a){
          cout<<"YES\n";
       }
       else{
          cout<<"NO\n";
       }
    }
}