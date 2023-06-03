#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    vector<int>v;
    for(int i = 0;i<s.size();i++){
         int t = s[i] - 48;
         if(t%2 == 0){
            v.push_back(i);
         }
    }
    if(v.size() == 0){
        cout<<-1;
        return  0;
    }
    int flag = 0;
    for(int i = 0;i<v.size();i++){
      if(s[v[i]] < s[s.size()-1]){
           char c = s[v[i]];
          s[v[i]] =  s[s.size() - 1];
          s[s.size() - 1] =c;
          flag = 1;
          break;
      }
    }
    if(flag == 1){
        cout<<s;
    }
    else{
         char c = s[v[v.size() - 1]];
          s[v[v.size()- 1]] =  s[s.size() - 1];
          s[s.size() - 1] =c;
          cout<<s;
    }
    return 0;
}