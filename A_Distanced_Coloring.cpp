#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;

     while(t--){
         int n,m,k;
         cin>>n>>m>>k;
         cout<<min({n*m,n*k,k*m,k*k})<<endl;
     }
}