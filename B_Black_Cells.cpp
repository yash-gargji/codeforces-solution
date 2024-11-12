#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        long long arr[n];

        for(int i = 0;i<n;i++){
           cin>>arr[i];
        }
        if(n % 2 == 0){
           long long int ans = 0;
           for(int i = 1;i<n;i += 2){
               ans = max(ans,arr[i] - arr[i-1]);
           }
          cout<<ans<<endl;
        }
        else{
            long long int ans = 1e18;

            for(int i = 0;i<n;i++){
               if(i % 2 )
                  continue;
                long long num = 0;
                for(int j = 1;j<i;j+= 2){
                    num = max(num,arr[j] - arr[j-1]);
                }
                for(int j = i+2;j<n;j+=2){
                   num = max(num,arr[j] - arr[j-1]);
                }
                ans = min(ans,num);
            }
           cout<<(ans == 0 ? 1 : ans)<<endl;
        }
    }
}