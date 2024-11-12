#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int x,y,k;
        cin>>x>>y>>k;

        cout<<"0 0 "<<min(k,x)<<" 0\n";
        cout<<"0 0 0 "<<min(k,y)<<endl;
    }
}