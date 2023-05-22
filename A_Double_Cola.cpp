#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin>>n;
    int num = 5;
    while(n > num){
        n = n - num;
        num = num*2;
    }
    num = num/5;
    int k = n/num;
    if(k*num != n){
          k= k +1;
    }
    if(k == 1){
        cout<<"Sheldon\n";
    }
    else if(k == 3){
        cout<<"Penny";
    }
    else if(k == 2){
        cout<<"Leonard";
    }
    else if(k == 4){
        cout<<"Rajesh";
    }
    else{
        cout<<"Howard";
    }
    return 0;
}