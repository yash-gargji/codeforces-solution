#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int a;
    cin>>a;
    while(a--){
        int x;
        cin>>x;
        
    int arr[x];
    for(int i  = 0;i<x;i++){
        cin>>arr[i];
    }
      int arr1[x];
    for(int i  = 0;i<x;i++){
        cin>>arr1[i];
    }
    for(int i = 0;i<x-1;i++){
     for(int j = i+1;j<x;j++){
        if(arr[j] < arr[i]){
            if(arr1[j] != arr1[i]){
                swap(arr[j],arr[i]);
                 swap(arr1[j],arr1[i]);
            }
        }
     }
    }
    int flag = 0;
    for(int i = 0;i<x-1;i++){
      if(arr[i] > arr[i+1]){
        cout<<"No\n";
        flag = 1;
        break;
      }
    }
    if(flag == 0){
        cout<<"Yes\n";
    }
}
}