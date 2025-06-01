#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
       int n,q;
       cin>>n>>q;

       vector<int>v(n);
       vector<int>ad[q];
       vector<int>c(n,0);

       for(int i = 0;i<n;i++){
           cin>>v[i];
           c[i] = v[i];
       }
       for(int i = 0;i<q;i++){
           int x,y,z;
           cin>>x>>y>>z;
           ad[i].push_back(x-1);
           ad[i].push_back(y-1);
           ad[i].push_back(z-1);
       }

       for(int i = q-1;i >= 0;i--){
           int x = ad[i][0],y = ad[i][1],z = ad[i][2];
           int val = c[z];
           c[z] = 0;
           c[x] = max(c[x],val);
           c[y] = max(c[y],val);
       }
       vector<int>ans = c;

       for(int i = 0;i<q;i++){
          int x = ad[i][0],y = ad[i][1],z = ad[i][2];
          c[z] = min(c[x],c[y]);
       }
     
       if(c == v){
         for(auto it:ans){
             cout<<it<<" ";
         }
       }
       else 
         cout<<-1;
        cout<<endl;
    }
}