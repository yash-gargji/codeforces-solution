#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     while(t--){
       long long int x,y;
     cin>>x>>y;
     if( x%y == 0 && (x*y != x || x*y != y)){
        cout<<"NO\n";
     }
      else{
        cout<<"YES\n";
         cout<<x<<" "<<x*y<<" "<<x*y+x<<endl;
    }
     }
    return 0;
}