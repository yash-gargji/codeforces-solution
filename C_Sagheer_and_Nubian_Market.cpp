#include<bits/stdc++.h>
using namespace std;

int main(){
      long long int n,s;
      cin>>n>>s;
      int arr[n];
      for(int i = 0;i<n;i++){
        cin>>arr[i];
      }
      sort(arr,arr+n);
     long long int pre[n];
      pre[0] = arr[0];

      for(int i = 1;i<n;i++){
          pre[i] = pre[i-1] + arr[i];
      }
      long long int sum,num;
      for(int i = n-1;i>= 0 ;i--){
            num = ((i+1)*(i+1)*(i+2))/2;  
            sum = pre[i] +  num;
            if(sum <= s){
                cout<<i+1<<" "<<sum;
                return 0;
            }
      }
      cout<<"0 0 ";
}