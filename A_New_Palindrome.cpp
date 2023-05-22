#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
     while(t--){
        string s;
        cin>>s;
        if(s.size() == 2){
            cout<<"NO\n";
            continue;
        }
        int flag = 0;
        for(int i = 1;i< s.size()/2;i++){
           if(s[i] != s[i-1]){
               flag = 1;
               break;
           }
        } 
        if(flag == 1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
     }
     return 0;
}