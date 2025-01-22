#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
       int arr[n];
       
       vector<int>po,ng;
       
       for(int i = 0;i<n;i++){
           cin>>arr[i];
           if(arr[i] >= 0){
              po.push_back(arr[i]);
           }
           else{
             ng.push_back(arr[i]);
           }
       }
       int low = 0;
       int high = 1e9*n;

       while(low <= high){
           int mid = (low + high)/2;
           int flag = 1;
           int sum = 0;
           int ind = 0;
           for(int i = 0;i<po.size();i++){
              if(po[i] > mid){
                  flag = 0;
                  break;
              }
              while(ind < ng.size() && sum + po[i] > mid){
                    sum += ng[ind++];
                    if(sum < 0)
                      sum = 0;
              }
              sum += po[i];
              if(sum > mid){
                 flag = 0;
                 break;
              }
           }
           if(flag){
            high = mid - 1;
           }
           else 
             low = mid + 1;
       }
       cout<<low<<endl;
       
    }
    return 0;
}