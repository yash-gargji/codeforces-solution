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
             if(s[0] != 's' && s[0] != 'e' && s[0] != 'Y'){
                cout<<"NO\n";
                continue;
             }
             int flag = 0;
             for(int i = 1;i<s.size();i++){
                if(s[i] == 's'){
                    if(s[i-1] != 'e'){
                        flag = 1;
                        break;
                    }
                }
                else if(s[i] == 'Y'){
                    if(s[i-1] != 's'){
                        flag = 1;
                        break;
                    }
                }
               else if(s[i] == 'e'){
                    if(s[i-1] != 'Y'){
                        flag = 1;
                        break;
                    }
                }
                else {
                    flag = 1;
                    break;
                }
             }
             if(flag == 1){
                cout<<"NO\n";
             }
             else{
                cout<<"YES\n";
             }
        
       }
}