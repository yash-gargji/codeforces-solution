#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int a,b;
        cin>>a>>b;
        
        if(a %2 == 1 || (b % 2  && a == 0)){
             cout<<"NO\n";
        }
        else{
             cout<<"YES\n";
        }
        
    }
}