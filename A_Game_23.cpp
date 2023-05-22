#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int x,y;
    cin>>x>>y;
    if(y%x != 0){
        cout<<"-1";
        return 0;
    }
    int count = 0 ;
    long long int num = y/x;
    while(num > 1){
         if(num%3 == 0){
            num = num/3;
            count++;
         }
         else if(num%2 == 0){
            num = num/2;
            count++;
         }
         else{
            cout<<-1;
            return 0;
         }
    }
    cout<<count;
    return 0;
}