#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
      ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
          int arr[n];
           int ans = 0;

          for(int i = 0;i<n;i++){
              cin>>arr[i];
          }
          sort(arr,arr+n);
          if(n == 1){
            cout<<"0\n";
            continue;
          }

          int count = 1;
          for(int i = 1;i<n;i++){
                   if(abs(arr[i] - arr[i-1]) <= k){
                        count++;
                         ans = max(ans,count);
                   }
                   else{
                        ans = max(ans,count);
                    
                        count = 1;
                   }
          }
          cout<<n - ans<<endl;
    }
    
}