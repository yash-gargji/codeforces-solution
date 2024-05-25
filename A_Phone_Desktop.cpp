#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
           int x,y;
           cin>>x>>y;

            int count = (y+1)/2;
              
               
                  x = x - count*7;
                if(y%2){
                     x = x - 4;
                }
                if(x > 0){
                   count += x/15;
                   if(x%15)
                    count++;
                }
              
          cout<<count<<endl;
     }
}