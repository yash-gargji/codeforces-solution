#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    while(a--){
        int a;
        cin>>a;
        set<string>s;
        for(int i = 0;i<a;i++){
            string str;
            cin>>str;

            s.insert(str);
        }
        for(auto &value: s){
            cout<<value<<endl;
        }
    }
    return 0;
}