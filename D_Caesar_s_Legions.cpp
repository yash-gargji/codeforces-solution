#include<bits/stdc++.h>
using namespace std;

int dp[101][101][11][11];
int n1,n2,k1,k2;

int mod = 1e8;

int memo(int num1,int num2,int k1c, int k2c){
      if(k1c > k1 || k2c > k2 || num1 < 0 || num2 < 0)
         return 0;
      if((num1 == 0 && num2 == 0)){
           return 1;
      }
       if(dp[num1][num2][k1c][k2c] != -1){
           return dp[num1][num2][k1c][k2c];
       }
     return dp[num1][num2][k1c][k2c] = (memo(num1 - 1,num2,k1c+1,0) + memo(num1,num2 - 1,0,k2c+1))%mod;
}

int main(){  

      cin>>n1>>n2>>k1>>k2;
      memset(dp,-1,sizeof(dp));
      cout<< memo(n1,n2,0,0);

}