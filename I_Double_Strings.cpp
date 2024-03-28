#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
          int n;
          cin>>n;
          unordered_map<string,int>m;
          string s[n];

          for(int i = 0;i<n;i++){
               cin>>s[i];
               m[s[i]]++;
          }
         for(int i = 0;i<n;i++){
            int flag = 0;
              for(int j = 0;j<s[i].size() - 1;j++){
                    if(m.count(s[i].substr(0,j+1))){
                          if(s[i].substr(0,j+1) == s[i].substr(j+1,s[i].size() - j - 1) && m[s[i].substr(j+1,s[i].size() - j - 1)] == 2){
                               flag = 1;
                               break;
                          }
                          else if(m.count(s[i].substr(j+1,s[i].size() - j - 1))){
                              flag = 1;
                              break;
                          }
                    }
              }
            cout<<flag;
         }
        cout<<endl;
    }


}