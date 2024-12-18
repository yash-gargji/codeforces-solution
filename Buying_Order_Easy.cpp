#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
         int n;
            cin>>n;
            int arr[n];
            int ct=2*n-2;
            for(int i=0;i<n;i++){
                cin>>arr[i];
            }
            if(arr[0]==1 or arr[n-1]==0){
                ct++;
            }
            cout<<ct<<endl;
     }
}