#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    while(a--){
        int a,b;
        cin>>a>>b;
       long int arr[a];
        for(int i = 0;i<a;i++){
             cin>>arr[i];
        }
       unsigned long long int pre[a+1];
        pre[0] = 0;
        pre[1]= arr[0];
        for(int i = 2;i<=a;i++){
            pre[i] = pre[i-1] + arr[i-1];
        }
        for(int i = 0;i<b;i++){
           long int x,y,k;
            cin>>x>>y>>k;
            if(x == y){
                   unsigned long long int sum = pre[a] - arr[x-1] + k;
                     if(sum%2 == 1){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
            continue;
            }
             unsigned long long int sum1 =k*(y-x +1);

             unsigned long long int sum = pre[a] - pre[y] + pre[x-1] + sum1 ;
            if(sum%2 == 1){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }
}