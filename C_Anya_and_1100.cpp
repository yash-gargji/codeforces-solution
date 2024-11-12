#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
         string s;
         cin>>s;
         set<int>st;
         string k = "1100";
         for(int i = 0;i<=s.size() - 4;i++){
            int flag = 1;
             for(int j = i;j<i+4;j++){
                 if(s[j] != k[j-i]){
                   flag = 0;
                 }
             }
            if(flag)
              st.insert(i);
         }
     }
}