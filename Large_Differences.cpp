#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n,k;
         cin>>n>>k;
          int arr[n];
          int sum = 0;

          for(int i = 0;i<n;i++){
               cin>>arr[i];
               if(i > 0){
                  sum += abs(arr[i] - arr[i-1]);
               }
          }
          int ans = sum;
          if(n == 1){
            cout<<0<<endl;
            continue;
          }
        for(int i = 0;i<n;i++){
             if(i == 0){
                 int num = sum;
                 num -= abs(arr[i+1] - arr[i]);
                 num = max(num,max(num + abs(arr[1] - k),num + abs(arr[1] - 1)));
                 ans = max(ans,num);
             }
             else if(i == n-1){
                   int num = sum;
                 num -= abs(arr[i-1] - arr[i]);
                 num = max(num,max(num + abs(arr[i-1] - k),num + abs(arr[i-1] - 1)));
                 ans = max(ans,num);
             }
             else{
                 int num = sum;
                 num = num - abs(arr[i+1] - arr[i]) - abs(arr[i] - arr[i-1]);
                 int a = max(num,num + abs(arr[i+1] - k) + abs(arr[i-1] - k));
                 int b =  max(num,num +abs(arr[i+1] - 1) + abs(arr[i-1] - 1));
                  if(min(arr[i+1],arr[i-1]) <= k)
                    num = max(num,num +arr[i+1] - arr[i-1]);
                 ans = max(ans,max(a,b));
             }
        }
       cout<<ans<<endl;
    }
}