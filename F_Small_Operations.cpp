#include<bits/stdc++.h>
using namespace std;

int func(int x,int k){
     map<int,int>mp;

     for(int i = 1;i*i <= x;i++){
         if(x % i == 0){
            mp[i] = 50;
            mp[x/i] = 50;
         }
     }
     mp[1] = 0;
     
     for(auto it:mp){
         if(it.second >= 50)
           continue;
        for(auto itr:mp){
            if(itr.first > k)
              break;
            long long p = 1ll*it.first*itr.first;
            if(mp.count(p))
               mp[p] = min(mp[p],it.second + 1);
        }
     }
    return mp[x];
}

int main(){
    int t;
    cin>>t;

    while(t--){
       int x,y,k;
       cin>>x>>y>>k;
       int gcd = __gcd(x,y);
       x /= gcd;
       y /= gcd;
       x = func(x,k);
       y = func(y,k);
       if(x + y >= 50)
         cout<<"-1\n";
       else 
         cout<<x + y << endl;
    }
}