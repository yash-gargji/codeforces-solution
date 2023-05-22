#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int arr[3];
    cin>>arr[0]>>arr[1]>>arr[2];
    sort(arr,arr+3);
    if(arr[2] <= 2*(arr[0] + arr[1])){
        long long int sum = (arr[0] + arr[1] + arr[2])/3;
        cout<<sum<<endl;
    
    }
    else if(2*arr[2] >= arr[0] + arr[1]){
        cout<<arr[0] + arr[1];
    
    }
   return 0;
}