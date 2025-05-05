#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int x,y,a;
        cin>>x>>y>>a;

        a = a % (x + y);
        if(x > a){
           cout<<"NO\n";
        }
        else{
          cout<<"YES\n";
        }
    }
}