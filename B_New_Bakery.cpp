#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
         long long int n,a,b;
         cin>>n>>a>>b;
         long long int num = b - a ;
         num = max(num,0ll);
         num = min(n,num);
         cout<<(num * b - (num - 1)*num/2) + (n - num)*a<<endl;
    }
}