#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;
      
      while(t--){
           int n;
            cin>>n;
            string s,t;
            cin>>s>>t;
            int l = -1;
            int flag = 1;
            for(int i=0;i<n;i++){
                if(s[i]=='0' and t[i] == '1'){
                    if(l ==- 1){
                        flag =0;
                        break;
                    }
                }
                if(s[i]=='1') 
                  l=1;
            }
            if(flag){
                 cout<<"YES\n";
            }
            else{
                 cout<<"NO\n";
            }
      }
}