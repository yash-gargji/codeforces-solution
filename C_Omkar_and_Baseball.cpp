#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        int arr[a];
        for(int i=0;i<a;i++ ){
            int num;
            cin>>num;
            arr[i] = abs(i+1 - num);
        }
        int f = -1;
        int r = a;
        for(int i = 0;i<a;i++){
            if(arr[i] !=  0){
                  f = i;
                  break;
            }
        }
        if(f == -1){
            cout<<"0\n";
            continue;
        }
        for(int i = a-1;i>=0 ;i--){
            if(arr[i] != 0){
                r = i;
                break;
            }
        }
        if(f == r){
            cout<<"2\n";
            continue;
        }
        int flag = 1;
        for(int i = f;i<= r;i++){
            if(arr[i] == 0 ){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            cout<<"1\n";
        }
        else{
            cout<<"2\n";
        }
    }
}