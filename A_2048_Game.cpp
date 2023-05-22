#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    while(a--){
        int x;
        cin>>x;
        int arr[x];
        for(int i  =0;i<x;i++){
            cin>>arr[i];
        }
        sort(arr,arr+x);
        int sum = 0;
        int j  = 0;
        int flag  = 0;
        for(int i  = 0;i<x;i++){
            sum = sum +arr[i];
            if(sum == 2048){
                cout<<"YES\n";
                flag = 1;
                break;
            }
            else if(sum <2048){
                continue;
            }
            else{
                while(sum>2048){
                    sum = sum - arr[j];
                    j++;
                }
                if(sum==2048){
                    cout<<"YES\n";
                    flag= 1;
                    break;
                }
            }
        }
        if(flag == 1){
            continue;
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}