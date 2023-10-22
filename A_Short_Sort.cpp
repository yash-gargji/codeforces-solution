#include<bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
      int t;
      cin>>t;
      
      while(t--){
            string s;
            cin>>s;
            if(s[0] == 'b' && s[1] == 'c' ){
                cout<<"NO\n";
            }
             else if(s[2] == 'b' && s[1] == 'a' ){
                cout<<"NO\n";
            }
            else {
                cout<<"YES\n";
            }
           
      }
}