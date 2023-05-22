#include<bits/stdc++.h>
using namespace std;

int main(){
   long int a;
    cin>>a;
    long int sum = 0;
   long int arr[9];
   

    for(int i = 0;i<9;i++){
        cin>>arr[i];
        sum = sum + arr[i];
    }
    if(*min_element(arr,arr+9) > a ){
        cout<<-1;
        return 0;
    }
    int max = 0;
    int r;
    for(int i = 0;i<9;i++){
        if(a/arr[i] >= max){
            max = a/arr[i];
            r = i+1;
        }
    }
    if(max  == 9 && a/sum == 1 && r != 9){
        for(int i = 9;i != 0;i--){
          cout<<i;
    }
    return 0;
    }
    for(int i = 0;i<max;i++){
          cout<<r;
    }
    return 0;
            
}