#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
      string s;
      cin>>s;
      vector<int>v;
      for(int i = 0;i<s.size();i++){
            if(s[i] != '?'){
                v.push_back(i);
            }
      }
      if(v.size() == 0){
        
        for(int i = 0;i<s.size();i++){
            cout<<0;
        }
         cout<<endl;
         continue;
      }
      else if(v.size() == s.size()){
            cout<<s<<endl;
            continue;
      }

      for(int i = 0;i<v[0];i++){
            s[i] = '0';
      }
      
      for(int i = v[v.size()-1] + 1;i<s.size();i++){
            s[i] = '1';
      }
      for(int i = 0;i<v.size()-1;i++){
        char c;
        if(s[v[i]] == '1' && s[v[i+1]] == '1'){
            c = '1';
        }
        else{
            c = '0';
        }
        for(int j = v[i]+1;j<v[i+1];j++){
              s[j] = c;
        }
      }
      cout<<s<<endl;
     
    }
      return 0; 
}