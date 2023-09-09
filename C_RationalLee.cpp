#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        int arr[n];
      for(int i = 0;i<n;i++){
          cin>>arr[i];
      }
         int num[n];
      for(int i = 0;i<k;i++){
            cin>>num[i];
      }
      long long int sum = 0;
      sort(arr,arr+n,greater<int>());
      sort(num,num+k);
      int r = k - 1;
       
      for(int i = 0 ; i < k; i++){
           if(num[i] == 1){
             sum += 2*arr[i];
             }
           else{
               sum += arr[i];
           }
           
      }
      for(int i = 0;i<k;i++){
              if(num[i] == 1){
                continue;
              }
              r = r + num[i] - 1; 
              sum += arr[r];
              
      }
      cout<<sum<<endl;
    }
}