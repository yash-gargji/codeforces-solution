#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int arr[n][n];
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
               cin>>arr[i][j];
            }
        }
      for(int i = 0;i<n;i++){
          int r = i;
          int c = 0;
          int ma = 0;

          while(r < n && c < n){
              if(arr[r][c] < 0)
                ma = max(ma,-arr[r][c]);
              r++;
              c++;
          }
          ans += ma;
      }
      for(int i = 1;i<n;i++){
          int r = 0;
          int c = i;
          int ma = 0;

          while(r < n && c < n){
              if(arr[r][c] < 0)
                ma = max(ma,-arr[r][c]);
              r++;
              c++;
          }
          ans += ma;
      }
     cout<<ans<<endl;
    }
}