#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;

        c -= (b - a);
        if(c >= b && (c - b) % 3 == 0){
           cout<<"YES\n";
        }
        else{
             cout<<"NO\n";
        }


    }
}