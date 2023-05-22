#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    while(a--){
        int n;
       cin>>n;
        int arr[n];
        for(int i = 0;i<n;i++){
               cin>>arr[i];
        }
        if(*min_element(arr,arr+n) == arr[0]){
            cout<<"Bob\n";
        }
        else{
            cout<<"Alice\n";
        }
    }
    return 0;
}