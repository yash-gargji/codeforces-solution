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
        
        int flag = 0;
        
        int l = -1;
        int r = -1;
        
        for(int i = 1;i<n;i++){
           if(i - 2 >= 0 && s[i] == s[i-1] && s[i-1] == s[i-2]){
              flag = 1;
              break;
           }
           if(s[i] == s[i-1]){
             if(l == -1){
                  l = i;
             }
             else if(r == -1){
                  r = i;
             }
             else{
                flag = 1;
                break;
             }
           }
        }
        if(flag == 1){
           cout<<"No\n";
        }
        else if(r == -1 && (s[l] == s[0] && s[l] == s[n-1])){
             cout<<"No\n";
        }
        else if(l != -1 && r != - 1 && s[l] == s[r]){
           cout<<"No\n";
        }
        else{
            cout<<"Yes\n";
        }
    }
}