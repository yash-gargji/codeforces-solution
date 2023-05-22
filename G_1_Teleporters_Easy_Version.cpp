#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    while(a--){
        int x;
        cin>>x;
       long int c;
        cin>>c;
        int arr[x];
        for(int i = 0;i<x;i++){
             cin>>arr[i];
             arr[i] = arr[i] + i+1;
        }
        long long int sum = 0;
        sort(arr,arr+x);
        int count = 0;
        for(int i = 0;i<x;i++){
              sum = sum + arr[i];
              if(sum<= c){
                count++;
              }
              else{
                break;
              }
        }
        cout<<count<<endl;
    }
    return 0;
}