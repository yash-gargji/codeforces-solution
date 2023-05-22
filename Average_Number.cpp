#include<bits/stdc++.h>
using namespace std;

int main(){
   int t;
   cin>>t;
   while(t--){
      long long int n,k,v;
       cin>>n>>k>>v;
        long long int sum = v*(n+k);
          long int arr[n];
          long long int y = 0;
            for(int i = 0;i<n;i++){
               cin>>arr[i];
              y = y + arr[i];
           }
           sum = sum - y;
           if(sum <= 0 || sum%k != 0){
            cout<<"-1\n";
           }
           else{
            cout<<sum/k<<endl;
           }
   }
   return 0;
}