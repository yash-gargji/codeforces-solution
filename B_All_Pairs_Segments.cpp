#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     while(t--){
         int n,q;
         cin>>n>>q;
         long long int arr[n];
         map<long long,long long>m;

         for(int i = 0;i<n;i++){
            cin>>arr[i];
         }
         for(int i = 0;i<n;i++){
             if(i == 0){
                m[n-1]++;
             }
             else if(i == n-1){
                 m[n-1]++;
             }
             else{
                m[1ll*(n - i)*(i) + n - i - 1]++;
             }
             if(i > 0){
                 m[1ll*(i)*(n-i)] += arr[i] - arr[i-1] - 1;
             } 
         }
         for(int i = 0;i<q;i++){
            long long num;
            cin>>num;
            cout<<m[num]<<" ";
         }
         cout<<endl;
     }
}