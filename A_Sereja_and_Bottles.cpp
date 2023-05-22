#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n ;
    int arr[n], arr1[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i]>>arr1[i];
    }
    int count = 0;
    for(int i = 0;i<n;i++){
        int flag = 1;
        for(int j = 0;j<n;j++){
            if(i == j){
                continue;
            }
            else if(arr[i] == arr1[j]){
                flag = 0;
                break;
            }
        }
        count = count + flag;
    }
   cout<< count;
   return 0;
}