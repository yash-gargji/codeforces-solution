#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int x,y;
        cin>>x>>y;

        if(y - x > 1 || y - x == 0){
            cout<<"No\n";
        }
        else if(y-x == 1 ||  (x - y + 1) % 9 == 0){
            cout<<"Yes\n";
        }
        else{
           cout<<"No\n";
        }
    }
}