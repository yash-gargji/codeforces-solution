#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;
      while(t--){
        int a,b,x,y,n,m;
        cin>>a>>b>>x>>y>>n>>m;
           int count = 1;
           if((x>=a && n>= a)|| (x<= a && n<= a)){
               count+= min(abs(x-a),abs(n-a));
           }
             if((y >= b && m >= b)|| (y <= b && m <= b)){
               count+= min(abs(y-b),abs(m-b));
           }
           cout<<count<<endl;
      }
}