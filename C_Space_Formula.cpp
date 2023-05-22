#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int arr[a];
    for(int i = 0;i<a;i++){
        cin>>arr[i];
    }
    int arr1[a];
    for(int i = 0;i<a;i++){
        cin>>arr1[i];
    }
    if(b == 1 || arr1[0] == arr1[a-1]){
        cout<<b;
        return 0;
    }
    int num = arr[b-1] + arr1[0];
    int r = 1;
    int count = 0 ;
    for(int i = b-2;i>= 0;i--){
        if(r == a || num < arr[i]){
            
            break;
        }
       else if(num >= arr[i] + arr1[r]){
            count++;
            r++;
        }
        else{
             
            for(int j = r;j<a;j++){
                   r = j+1;
                   if(num>= arr[i] + arr1[j]){
                     
                    count++;
                    break;
                   }
            }
        }
    }
    cout<<b - count;
    return 0;
}