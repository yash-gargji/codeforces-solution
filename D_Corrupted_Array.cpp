#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    while(a--){
        int n;
        cin>>n;
        int x = n+2;
        int arr[x];
        for(int i = 0;i<x;i++){
            cin>>arr[i];
        }
        sort(arr,arr+ x);
         long long int sum = 0;
        for(int i = 0;i<n;i++){
            sum = sum + arr[i];
        }
        if(sum == arr[n] || sum == arr[n+1]){
            for(int i = 0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            continue;
        }
         int flag = 0;
         int y = 0;
            sum = sum + arr[n];
            for(int i = 0;i<=n;i++){
                sum = sum - arr[i];
                if(sum == arr[n+1]){
                    flag = 1;
                    y = i;
                    break;
                }
                sum = sum + arr[i];
            }
            if(flag == 0){
                cout<<"-1\n";
            }
            else{
                for(int i = 0;i<=n ;i++){
                    if(i == y){
                        continue;
                    }
                    else{
                        cout<<arr[i]<<" ";
                    }
                }
                cout<<"\n";
            }
    }
    return 0;
}