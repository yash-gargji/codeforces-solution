#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
       int n;
       cin>>n;
       
       int arr[n],suff[n];
       int ma = 0;
       
       for(int i = 0;i<n;i++){
           cin>>arr[i];
           suff[i] = ma;
           ma = max(ma,arr[i]);
       }
       long long sum = 0;
       int mi = INT_MAX;

       for(int i = n-1;i>= 0;i--){
          mi = min(mi,arr[i]);
          cout<<max(sum+arr[i],sum + suff[i])<<" ";
          sum += arr[i];
       }
       cout<<endl;
       
    }
}