#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        unsigned long long int a,b,n,m;
        cin>>a>>b>>n>>m;
        if(a+b < m + n){
            cout<<"No\n"; 
        }
        else if( min(a,b) < m){
                cout<<"No\n"; 
        }
        else{
            cout<<"Yes\n";
        }
    }
    return 0;
}