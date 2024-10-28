#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
        long long  int n;
         cin>>n;
        long long int m,r,c;
         cin>>m>>r>>c;
         
        long long  int num = n*m - ((r - 1) * m + c);

         cout<<num + (num/m)*(m - 1)<<endl;
     }
}