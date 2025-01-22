#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
       map<int,vector<int>>m1,m2;
       int n;
       cin>>n;
       int arr[n];

       for(int i = 0;i<n;i++){
           cin>>arr[i];
           m1[__builtin_popcount(arr[i])].push_back(arr[i]);
           m2[__builtin_popcount(arr[i])].push_back(i);
       }
       for(auto it:m1){
          auto v1 = it.second;
          auto v2 = m2[it.first];
          sort(v1.begin(),v1.end());
          sort(v2.begin(),v2.end());
          
          for(int i = 0;i<v1.size();i++){
             arr[v2[i]] = v1[i];
          }
       }
       int flag = 1;
       
       for(int i = 1;i<n;i++){
           if(arr[i] < arr[i-1])
             flag = 0;
       }
       if(flag){
         cout<<"Yes\n";
       }
       else{
         cout<<"No\n";
       }
    }
    return 0;
}