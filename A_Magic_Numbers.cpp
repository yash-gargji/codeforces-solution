#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    if(s[0] == '4'){
        cout<<"NO";
        return 0;
    }
       int f = 1;
     for(int i = s.size()-1;i >= 0;i--){
        if(s[i] != '1' && s[i] != '4'){
            cout<<"NO";
            return 0;
        }
          if(s[i] == '4' ){
            int x = 0;
            if(i-1 == -1){
                cout<<"NO";
                return 0;
            }
            
            else{
                if(s[i-1] == '4'){
                    if(i-2 == -1){
                   cout<<"NO";
                  return 0;
                 } 
                 else if(s[i-2] != '1'){
                    cout<<"NO\n";
                    return 0;
                 }
                }
            }
        }
     }
     cout<<"YES";
     return 0;
}