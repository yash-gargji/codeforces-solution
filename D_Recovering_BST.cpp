#include<bits/stdc++.h>
using namespace std;
int arr[700];
int dp[700][700][2];
int adj[700][700];

int func(int l,int r,int t){
     if(l > r)
       return 1;
     if(dp[l][r][t] != -1){
        return dp[l][r][t];
     }
     int num = 0;
     if(t == 1){
        num = l-1;
     }
     else 
       num = r+1;
     dp[l][r][t] = 0;

     for(int i = l;i<= r;i++){
        if(adj[i][num] != 1)
            continue;
        if(func(l,i-1,0) && func(i+1,r,1)){
           dp[l][r][t] = 1;
           break;
        }
     }
     if(r - l == 0 && adj[l][num] )
       return dp[l][r][t] = 1;
    return dp[l][r][t];
}

int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    memset(adj,0,sizeof(adj));

    for(int i = 0;i<n;i++){
       cin>>arr[i];
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i == j || __gcd(arr[i],arr[j]) == 1)
              adj[i][j] = 0;
            else 
              adj[i][j] = 1;
        }
    }
    int fl = 0;

    for(int i = 0;i<n;i++){
        if(func(0,i-1,0) && func(i+1,n-1,1)){
            fl = 1;
            break;
        }
    }
   if(fl){
     cout<<"Yes\n";
   }
   else{
    cout<<"No\n";
   }
}