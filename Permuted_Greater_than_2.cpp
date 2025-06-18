#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int x,y,z;
        cin>>x>>y>>z;

        int fl = 0;

        if(y == 0 && z + 1 >= x)
          fl = 1;
        if(z >= x)
          fl = 1;
        if(fl){
           cout<<"Yes\n";
        }
        else{
         cout<<"No\n";
        }
    }
}