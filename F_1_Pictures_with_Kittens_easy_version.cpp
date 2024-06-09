#include<bits/stdc++.h>
using namespace std;

long long int dp[201][201][201];

long long  func(int ind,int sz,int cons,vector<long long>&nums,int k){
     if(cons == k || sz == -1 || (sz == 0 && ind + 1 == k))
         return INT_MIN;
      if(ind == 0){
          if(sz  > 1)
           return INT_MIN;
          else if(sz == 0)
           return 0;
           else 
            return nums[0];
      }
      if(dp[ind][sz][cons] != -1) 
        return dp[ind][sz][cons];
      long long take =   func(ind-1,sz-1,0,nums,k);
      long long not_take = func(ind-1,sz,cons+1,nums,k);
      if(take != INT_MIN){
         take += nums[ind];
      }

      return dp[ind][sz][cons] = max(take,not_take);
}


int main(){
    int n, k, x;
    cin >> n >> k >> x;
    vector<long long> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    memset(dp,-1,sizeof(dp));
    long long int val = func(n-1,x,0,nums,k);
    cout<<(val <= 0 ? -1 : val);
}
