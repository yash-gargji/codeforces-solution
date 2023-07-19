#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n,k;
    cin>>n>>k;
    pair<long long int,long long int>p[n];
    for(int i = 0;i<n;i++){
       long long int a,b;
        cin>>a>>b;
        p[i] = {a,b};
    }
    sort(p,p+n);
    long long int sum = 0;
      if(k == 0){
          long long int ans = p[n-1].first  + 1;
          cout<<ans;
          return 0;
      }
      long long int ans = p[n-1].first;
      int flag = -1;
      for(int i = n-1;i>= 0 ;i--){
        sum += p[i].second;
        if(sum <= k ){
            flag = i;
            ans = p[i].first;
        }
        else if(sum > k){
         ans = p[i].first + 1;
         break;
        }
      }
      if(flag == 0){
        cout<<1;
        return 0;
      }
      cout<<ans;
}