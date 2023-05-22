#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    int arr[x];
    for(int i = 0;i<x;i++){
        cin>>arr[i];
    }
      sort(arr,arr+x);
   if(x == y){
        cout<<arr[x-1];
        return 0;
    }
    
   else if(y == 0){
        if(arr[0] == 1){
            cout<<-1;
        }
        else{
            cout<<arr[0]-1;
        }
    }
    else if(arr[y] == arr[y-1]){
        cout<<-1;
        
    }
    else{
        cout<<arr[y-1];
    }
      return 0;
}