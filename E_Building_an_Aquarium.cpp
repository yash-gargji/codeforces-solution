#include<bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

      int t;
      cin>>t;
      
      while(t--){
                  int n,x;
               cin>>n>>x;
                  int arr[n];

            for(int i = 0;i<n;i++){
                cin>>arr[i];
            }
            sort(arr,arr+n);
           long long int ans = 0;
             long long int sum = 0;

            for(long long int i = 0; i <= n-1;i++){
                sum += arr[i];
                long long int high;
                   if(i == n-1){
                        high = INT_MAX;  
                   }
                  else{
                        high = arr[i+1];
                   }
            long long int low = arr[i];
              
            while(low <= high){
                long long int mid = (high - low)/2 + low;
                long long int num = mid*(i+1);
                      
                         if(num - sum - x == 0){
                             low = mid + 1;
                             ans = mid;
                             break;
                       }
                       else if(num - sum - x < 0){
                        low = mid + 1;
                        ans = mid;
                        
                       } 
                       else {
                           high = mid - 1;
                       }
            }  
        }
        if(ans == 0){
            ans = arr[0];
        }
            cout<<ans<<endl;
      }
}