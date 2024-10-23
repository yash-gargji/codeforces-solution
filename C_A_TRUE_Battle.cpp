#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
         
         int ans = 0;
         if(s[0] == '1' || s[n-1] == '1'){
             cout<<"YES\n";
             continue;
             
         }
         for(int i = 1;i<n;i++){
            if(s[i] == '1' && s[i-1] == '1'){
               ans = 1;
            }
         }
         cout<<(ans == 1 ? "YES\n" : "NO\n");
    }
}