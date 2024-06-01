#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int l,r;
        cin>>l>>r;
        int k = 1; 
        int ans = 0;
         for(int i = 1;i<30;i++){
           if((1  << i) >= l && (1 << i) <= r){
               ans = i;
           }
         }
        cout<<ans<<endl;
    }
}