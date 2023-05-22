#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    while(a--){
       int a;
       cin>>a;
       int arr[a];
       for(int i = a-1;i>=0;i--){
        cin>>arr[i];
       }
       stack<int>s;

       s.push(arr[0]);

         for(int i = 1;i<a;i++){
              if(arr[i] > s.top()){
                continue;
              }
              else{
                s.push(arr[i]);
              }
         }
         cout<<a- s.size()<<endl;
    }
    return 0;
}