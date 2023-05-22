#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int a;
        cin>>a;
       long long int sum = 0;
        while(1){
               if(a == 1){
                break;
               }
               else if( a&(a-1) == 0){
                sum = -1;
                break;
               }
               else if(a%6 == 0){
                a = a/6;
                sum++;
               }
               else{
                a = a*2;
                sum ++;
               }
        }
        cout<<sum<<endl;
    }
    return 0;
}