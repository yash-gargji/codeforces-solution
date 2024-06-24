#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;
      
      while(t--){
           int n,m;
           cin>>n>>m;

           int arr[n][m];

           for(int i = 0;i<n;i++){
             for(int j = 0;j<m;j++){
                  cin>>arr[i][j];
             }
           }
           vector<vector<int>>v(n,vector<int>(m));
          int dr[4] = {-1,0,1,0};
          int dc[4] = {0,-1,0,1};

          for(int i = 0;i<n;i++){
            for(int j  = 0;j<m;j++){
                 int flag = 1;
                  int count = 0;
                  int num = INT_MIN;
                  for(int k = 0;k<4;k++){
                     int nrow = i + dr[k];
                     int ncol  = j + dc[k];

                     if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                          if(arr[nrow][ncol] < arr[i][j]){
                              count++;
                               num = max(num,arr[nrow][ncol]);
                          }
                          else{
                             flag = 0;
                             break;
                          }
                     }
                  }
                if(flag && count){
                     v[i][j] = num;
                }  
                else{
                     v[i][j] = arr[i][j];
                }
              cout<<v[i][j]<<" ";
            }
            cout<<endl;
          }
      }
}