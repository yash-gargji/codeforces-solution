#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

   int t;
   cin>>t;
   while(t--){
      ll x,y;
      cin>>x>>y;
       unordered_set<ll>s;

       for(int i = 0;i<x;i++){
        ll num;
        cin>>num;
        s.insert(num);
       }
       for(int i = 0;i<y;i++){
        ll num;
        cin>>num;
        auto it = s.find(num);
        if(it == s.end()){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
        s.insert(num);
       }
   }
   return 0;
}