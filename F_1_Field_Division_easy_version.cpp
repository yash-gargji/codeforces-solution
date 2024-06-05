#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;

     while(t--){
         int n,m,k;
         cin>>n>>m>>k;
         long long ans = 0;
         map<int,map<int,int>>mp;
         vector<int>v(k+2);
         int prev = 0;
         int prev_row = 0;
         mp[1][0] = k;
         mp[m][1] = k+1;

         for(int i = 0;i<k;i++){
             int num1,num2;
             cin>>num1>>num2;
             mp[num2][num1] = i;
         }
         for(auto it:mp){
             ans += 1ll*(it.first - prev_row - 1)*(n - prev);
             prev_row = it.first;
             auto itr = it.second.end();
             itr--;
             int mn = min(n - itr->first,n - prev);
             ans += mn;
             if(prev < itr->first){
                 v[itr->second] = 1;
             }
             prev = max(prev,itr->first);
         }
         cout<<ans<<endl;
         for(int i = 0;i<k;i++){
             cout<<v[i]<<" ";
         }
        cout<<endl;
     }
}