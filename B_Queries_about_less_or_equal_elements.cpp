#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int arr1[a];
    int arr2[b];
    for(int i = 0;i<a;i++){
        cin>>arr1[i];
    }
     for(int i = 0;i<b;i++){
        cin>>arr2[i];
    }
    sort(arr1,arr1+a);
    
    for(int i = 0;i<b;i++){
         if(arr2[i] < arr1[0]){
            cout<<"0 ";
         }
         else{
            auto itr = lower_bound(arr1,arr1+a,arr1[0]) - arr1;
             auto it = upper_bound(arr1,arr1+a,arr2[i]) - arr1;
             cout<<it - itr<<" ";

         }
    }
}