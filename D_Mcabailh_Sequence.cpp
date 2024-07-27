#include <bits/stdc++.h>
using namespace std;

 
int main() {
    long long int x,y,m,a;
     cin>>x>>y>>m>>a;
     map<int,int>mp;

     int  count = 1;
     int ans = 0;
     mp[a] = 0;

     while(1){
        a = (a*x + y)%m;
        if(mp.find(a) != mp.end()){
          ans = count - mp[a];
          break;
        }
        mp[a] = count++;
     }
    cout<<ans<<endl;
}
