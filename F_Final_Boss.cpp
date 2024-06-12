#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
         long long int h, n;
         cin >> h >> n;
         vector<long long> a(n), c(n);

         for(int i = 0; i < n; i++){
              cin >> a[i];
         }
         for(int i = 0; i < n; i++){
              cin >> c[i];
         }
         
         long long low = 1;
         long long high = 1e13;
         long long ans = 1e13;

         while(low <= high){
              long long mid = low + (high - low) / 2;
              long long k = h;

              for(int i = 0; i < n; i++){
                   k -= ((mid - 1) / c[i] + 1) * a[i];
                   if (k <= 0) break;
              }

              if (k <= 0) {
                 ans = mid;
                 high = mid - 1;
              } else {
                  low = mid + 1;
              }
         }
        cout << ans << endl;
    }
}
