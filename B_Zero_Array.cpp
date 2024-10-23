#include<bits/stdc++.h>
using namespace std;

int main(){
     int n;
     cin>>n;
     int ma = 0;
    long long sum = 0;

    for(int i = 0;i<n;i++){
       int num;
       cin>>num;
        ma = max(ma,num);
        sum += num;
    }
    if(sum >= 2*ma && sum % 2 == 0)
      cout<<"YES";
    else 
      cout<<"NO";
}