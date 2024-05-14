#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
            string s;
            cin>>s;
             int count = 1;
             int flag = 0;

             for(int i = 1;i<s.size();i++){
                 if(s[i] != s[i-1]){
                    count++;
                    if(s[i] == '1' && s[i-1] == '0')
                      flag = 1;
                 }
             }
            cout<<count - flag<<endl;
     }
}