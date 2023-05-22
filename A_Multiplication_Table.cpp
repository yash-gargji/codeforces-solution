#include<bits/stdc++.h>
using namespace std;

int main(){
    long int x,y;
    cin>>x>>y;
    int count  = 0;
   
    for(int i = 1;i<=min(x,y);i++){
        if(y%i == 0){
            if(y/i<=x){
            count++;
            }
        }
    }
    cout<<count ;
}