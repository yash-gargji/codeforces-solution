#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int arr[n];
         
        for(int i = 0;i<n;i++){
           cin>>arr[i];
        }
       int ans = 0;
       map<long long ,int>m;
       long long sum = 0;
       m[0] = 0;
       int prev = 0;
       for(int i = 0;i<n;i++){
          sum += arr[i];
          if(m.find(sum) != m.end() && m[sum] >= prev){
             sum = 0;
             ans++;
             m[0] = i + 1;
             prev = i+1;
          }
          else  
            m[sum] = i;
       }
      cout<<ans<<endl;
    }
}