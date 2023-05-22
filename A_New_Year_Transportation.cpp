#include<bits/stdc++.h>
using namespace std;

int main(){
    long int a,b;
    cin>>a>>b;
    int arr[a];
    arr[0] = 1;
   int sum = 0;
   for(int i = 1;i<a;i++){
    cin>>arr[i];
   }
   while(sum != a){
    sum = sum + arr[sum];
    if(sum == b ){
        cout<<"YES";
        return 0;
    }
    else if(sum > b){
        cout<<"NO";
        return 0;
    }
   }
   return 0;
}