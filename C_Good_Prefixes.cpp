#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
          int n;
          cin>>n;
          vector<long long int> arr(n);  
          long long int sum = 0;
          int ans = 0;

          for(int i = 0; i < n; i++){
               cin >> arr[i];
          }
         long long int ma = 0;
          for(int i = 0; i < n; i++){
               ma = max(ma,arr[i]);
              sum += arr[i];
              if(sum - ma == ma)
                ans++;
          }
        cout << ans << endl;
    }
}
