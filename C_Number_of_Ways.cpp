#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin>>n;
      long long int sum = 0,ans = 0,num = 0;
      map<long long,int>m;
      long long pre[n];

      int arr[n];

      for(int i = 0;i<n;i++){
         cin>>arr[i];
         sum += arr[i];
      }
      pre[n-1] = arr[n-1];
      for(int i = n-2;i >=0; i--){
          pre[i] = pre[i+1] + arr[i];
      }
      
      for(int i = 0;i<n-1;i++){
          num += arr[i];
           if(num - pre[i+1] == pre[i+1])
             ans += m[num - pre[i+1]];
          m[num]++;
      }
      cout<<ans;
}