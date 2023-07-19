#include<bits/stdc++.h>
using namespace std;

int main(){  
    int t;
    cin>>t;
    while(t--){
         int n,m,k;
         cin>>n>>m>>k;
         int x,y;
         cin>>x>>y;
         int flag = 0;
         for(int i = 0;i < k;i++){
            int a,b;
            cin>>a>>b;
              if((abs(a-x) + abs(b-y))%2 == 0 && !flag){
                
                   cout<<"NO\n";
                   flag = 1;
                   
              }
         }
         if(!flag){
            cout<<"YES\n";
         }
    }
    return 0;
}