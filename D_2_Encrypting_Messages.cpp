#include<bits/stdc++.h>
using namespace std;

int main(){
        int n,m,c;
        cin>>n>>m>>c;
       int arr[n];
       for(int i = 0;i<n;i++){
        cin>>arr[i];
       }
       vector<int>d(n+1);
       for(int i = 0;i<n;i++){
        if(i == 0){
            d[i] = arr[i];
        }
        else{
            d[i] = arr[i] - arr[i-1];
        }
       }
       for(int i = 0;i<m;i++){
        int num;
        cin>>num;
         d[i] = d[i] + num;
         d[n-(m-(i+1))] -= num;
       }
       for(int i = 0;i<n;i++){
        if(i == 0){
            cout<<d[i]%c<<" ";
        }
        else{
            d[i] += d[i-1];
            cout<<d[i]%c<<" ";
        }
       }
}