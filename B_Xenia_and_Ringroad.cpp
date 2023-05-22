#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n,m;
    cin>>n>>m;
    long long int a[m];
    for(int i =0;i<m;i++){
        cin>>a[i];
    }
    long long int sum = 0,x = 0;
    x = a[0] - 1;
    sum += x;
    for(int i =0;i<m-1;i++){
        x = a[i+1] - a[i];
        if(x < 0){
            x = n + x;
        }
        sum += x;
    }
    cout<<sum;
    return 0;
}