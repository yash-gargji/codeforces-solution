#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    string s1;
    cin>>s>>s1;
      int count =  0;
         vector<int>v;

      for(int i = 0;i<s.size();i++){
        if(s[i] != s1[i]){
            v.push_back(i);
            count++;
        }
      }
      if(count != 2){
        cout<<"NO";
      }
      else{
        if(s[v[1]] == s1[v[0]] && s1[v[1]] == s[v[0]]){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
      }
}