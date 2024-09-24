#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
       int n,m,k;
       cin>>n>>m>>k;
       vector<int>arr(m);
       
       for(int i = 0;i<m;i++){
        cin>>arr[i];
       }
       sort(arr.begin(),arr.end());
        for(int i = 0;i<k;i++){
            int num;
            cin>>num;
           if(num < arr[0]){
             cout<<arr[0] - 1<<endl;
           }
           else if(num > arr[m-1]){
               cout<<n - arr[m-1]<<endl;
           }
           else{
              auto it = lower_bound(arr.begin(),arr.end(),num);
              int r = *it;
              --it;
              int l = *it;
              cout<<(r - l)/2<<endl;
           }
        }
    } 
}