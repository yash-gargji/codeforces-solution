#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    while(a--){
        long long int x,y;
        cin>>x>>y;
        if(x == y){
            cout<<2<<endl;
            cout<<x<<" "<<0<<endl;
        }
        cout<<1<<endl;
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}