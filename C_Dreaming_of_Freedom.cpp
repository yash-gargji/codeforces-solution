#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    while(a--){
        int x,y;
        cin>>x>>y;
        int flag =0;
    while(y > 0){
           if(y == 1){
            cout<<"YES\n";
            flag = 1;
            break;
           }
           y = x%y;
    }
    if(flag == 0){
        cout<<"NO\n";
    }
    }
    return 0;
}