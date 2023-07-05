#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
     long long int s1 = 0,s2 = 0;
     int n,m;
     cin>>n>>m;
     for(int i = 0 ;i<n; i++){
            int num;
            cin>>num;
            s1 = s1 + num;

     }
     for(int i = 0 ;i<m; i++){
            int num;
            cin>>num;
            s2 = s2 + num;
            
     }
     if(s1>s2){
        cout<<"Tsondu\n";
     }
     else if(s1 == s2){
          cout<<"Draw\n";
     }
     else{
           cout<<"Tenzing\n";
     }
    }
}