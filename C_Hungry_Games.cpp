#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;
      
      while(t--){
          map<int,int>m;
          int n,x;
          cin>>n>>x;
          x++;
          int arr[n];
          
          long long int sum = 0;
          long long int ans = 0;
          
          for(int i = 0;i<n;i++){
              cin>>arr[i];
    
              sum += arr[i];
             
              sum = sum%x;
              ans += i+1 - m[sum];
              m[sum]++;
              if(sum == 0)
                 ans--;
               cout<<sum<<" ";
          }
         cout<<ans<<endl;
      }
}