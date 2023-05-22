#include<bits/stdc++.h>
using namespace std;

int main(){
   int a;
   cin>>a;
   while(a--){
    long long int x,y;
    cin>>x>>y;
    map<long long int,long long int>m;
    for(int i = 0;i<x;i++){
        int a;
        cin>>a;
        m[a%y]++;  
    }
    m[0] = 0;
    long long int ans  = 0;
    for(auto it = m.begin();it != m.end();it++){
          if(it->second == 1){
            ans = max(ans,y - it->first);
          }
          else{
            ans = max(ans,y - it->first +( it->second-1)*y);
          }
    }
    if(ans == 0){
        cout<<0<<endl;
    }
    else{
        cout<<ans+1<<endl;
    }
   }
}