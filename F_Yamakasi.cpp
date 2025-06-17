#include<bits/stdc++.h>
using namespace std;
#define int long long

int func(int l,int r,map<int,vector<int>>&mp,int num){
     if(l > r)
       return 0;
     auto it = lower_bound(mp[num].begin(),mp[num].end(),l);
     auto itr = upper_bound(mp[num].begin(),mp[num].end(),r);

     return itr - it;
}

signed main(){
    int t;
    cin>>t;
    
    while(t--){
       int n,s,x;
       cin>>n>>s>>x;

       map<int,vector<int>>mp;
       int sum = 0;
       int ans = 0;
       int ind = -1;int last = -2;
       mp[0].push_back(-1);
       
       for(int i = 0;i<n;i++){
           int num;
           cin>>num;
           if(num > x)
             ind = i;
           if(num == x){
              last = i-1;
           }
           sum += num;
           num =  sum - s;

           ans += func(ind,last,mp,num);
           mp[sum].push_back(i);
       }
      cout<<ans<<endl;
    }
}