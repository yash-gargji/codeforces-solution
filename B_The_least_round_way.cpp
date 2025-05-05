#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n][n];

    for(int i  = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int dp[n][n][10];
    memset(dp,1e9,sizeof(dp));
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            int count = 0;
            int num = arr[i][j];

            while(num % 10 == 0){
                count++;
                num /= 10;
            }
            num = num % 10;
            if(i == 0 && j == 0){
                dp[i][j][num] = count;
                continue;
            }
            if(i != 0){
              for(int k = 1;k<10;k++){
                  if(dp[i-1][j][k] == 1e9)
                    continue;
                  int temp = k*num;
                  int ind = (temp % num == 0 ? temp/10 : temp % 10 );
                  dp[i][j][ind] = min(dp[i][j][ind],count + dp[i-1][j][k] + (temp % 10 == 0));
               }
            }
            if(j != 0){
              for(int k = 1;k<10;k++){
                  if(dp[i][j-1][k] == 1e9)
                    continue;
                  int temp = k*num;
                  int ind = (temp % num == 0 ? temp/10 : temp % 10 );
                  dp[i][j][ind] = min(dp[i][j][ind],count + dp[i][j-1][k] + (temp % 10 == 0));
               }
            }
        }
    }
    string s('0',2*n-2);
    int ind = 2*n-2;
    int i = n-1,j = n-1;

    while(i > 0 || j > 0){
         int mi = *min_element(dp[i][j],dp[i][j]+10);
         
    }
}