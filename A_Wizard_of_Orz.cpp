#include<bits/stdc++.h>
using namespace std;

int  main(){
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        if(a == 1)
        {
            cout<<"9\n";
            continue;
        }
        else if(a == 2){
            cout<<"98\n";
            continue;
        }
        else if(a == 3){
            cout<<"989\n";
            continue;
        }
        else{
            cout<<"989";
            for(int i = 4;i<=a;i++){
                cout<<(i - 4)%10;
            }
            cout<<endl;
        }
    }
    return 0;
}