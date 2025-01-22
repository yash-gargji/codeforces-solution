#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int ct=1;
        if(c==a+b+b)ct++;
        if(d==a+b+c)ct++;
        if(ct==3){
            cout<<ct<<endl;
            continue;
        }
        if((c-b)==(d-c))cout<<2<<endl;
        else {
            cout<<ct<<endl;
        }
    }
}