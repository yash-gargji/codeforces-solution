#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
         int n,m,k;
         cin>>n>>m>>k;

         vector<vector<int>>grid(n,vector<int>(m));

         if(k % n == 0 && k / n > 1){
            int num = 0;

            for(int i = 0;i<m;i++){
                for(int j = 0;j<n;j++){
                     grid[j][i] = num + 1;
                     num = (num + 1) % k;
                }
            }
         }
         else if(k % m == 0 && k/m > 1){
            int num = 0;

            for(int i = 0;i<n;i++){
                for(int j = 0;j<m;j++){
                     grid[i][j] = num + 1;
                     num = (num + 1) % k;
                }
            }
         }
         else {
            int num = 0;

            for(int i = 0;i<m;i+= 2){
                for(int j = 0;j<n;j++){
                     grid[j][i] = num + 1;
                     num = (num + 1) % k;
                }
            }
            for(int i = 1;i<m;i+= 2){
                for(int j = n-1;j >= 0;j--){
                     grid[j][i] = num + 1;
                     num = (num + 1) % k;
                }
            }

         }
         for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}