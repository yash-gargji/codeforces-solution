#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
      int t;
      cin>>t;
      
      while(t--){
           int a,b,c;
           cin>>a>>b>>c;

           if(a < b && b < c){
            cout<<"STAIR\n";
           }
           else if(b > a && b > c){
            cout<<"PEAK\n";
           }
           else {
            cout<<"NONE\n";
      }
          
      }
}