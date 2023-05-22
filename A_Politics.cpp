#include<bits/stdc++.h>
using namespace std;

int main(){
      int a;
      cin>>a;
      while(a--){
         int x,k;
         cin>>x>>k;
             
            string s;
            cin>>s;
             stack<string>v;
             v.push(s);
           for(int i = 1;i<x;i++){
            string a;
            cin>>a;
             if(v.top() == a){
                 v.push(a);
             }
             else{
                continue;
             }
           }
        
            cout<<v.size()<<endl;
      }
      return 0;
}