#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
           cin>>n;
           int m,k;
           cin>>m>>k;

           int num = n/m;
           if(n%m  >  0){
               num++;
           }
           if(k  >=  n - num){
              cout<<"NO\n";
           }
           else{
             cout<<"YES\n";
           }

}

int main(){
     int t;
     cin>>t;
     
     while(t--){
            solve();
     }
}