#include<bits/stdc++.h>
using namespace std;

int main(){
       int t;
       cin>>t;
       while(t--){
            string s;
            cin>>s;
              int count = 0;
               set<int>se;
             
             int flag = 0;
             for(int i = 0;i<s.size();i++){
                    if(s[i] == 'A'){
                          int l = i;
                          for(int j = i + 1; j<s.size();j++){
                              if(s[j] == 'A'){
                                  i = j;
                              }
                              else {
                                break;
                              }
                          }
                          int p = i - l + 1;
                          count += p;
                          se.insert(p);
                    }
                    else if(i != s.size() && s[i+1] == 'B'){
                           flag = 1;
                    }
             }
             if((s[0] == 'B' || s[s.size() - 1] == 'B') || flag == 1){
                     cout<<count<<endl;
             }
             else{
                  auto it = se.begin();
                      cout<<count - *it <<endl;
             }
       }
}