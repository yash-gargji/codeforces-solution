#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
         int n;
         cin>>n;
         int arr[n];
          long long int x = 0,y = 0;
          for(int i = 0;i<n;i++){
            cin>>arr[i];
            if(arr[i] == 1){
                x = x + i+1;
            }
            else{
                y = y + i+1;
            }
          }
          cout<<abs(x-y)<<endl;
    }
    return 0;
}