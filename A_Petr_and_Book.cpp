#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[7];
    for(int i = 0;i<7;i++){
        cin>>arr[i];
    }
    int sum = 0;
    int i = 0;
    while(sum < n){
        sum = sum + arr[i%7];
        i++;
    }
    if(i%7 == 0){
        cout<<7;
        return 0;
    }
    cout<<i%7;
    return 0;
}