#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;

     while(t--){
        int n ;
        cin>>n;
        string s;
        cin>>s;

        vector<int>ans;
        int flag = 1;

        while(ans.size() <= 2*n){
              vector<pair<int,char>>v = {{0,'T'},{0,'I'},{0,'L'}};
              for(int i = 0;i<s.size();i++){
                  if(s[i] == 'T'){
                     v[0].first++;
                  }
                  else if(s[i] == 'I'){
                     v[1].first++;
                  }
                  else {
                     v[2].first++;
                  }
              }
              sort(v.begin(),v.end());
              if(v[0].first == v[1].first && v[1].first == v[2].first)
                break;
             int pos = -1;
             char c = 'a';
             
             for(int i = 0;i<s.size()-1;i++){
                 if(s[i] != s[i+1] && s[i] != v[0].second && s[i+1] != v[0].second){
                    pos = i+1;
                    c = v[0].second;
                    break;
                 }
                 else if(s[i] != s[i+1] && s[i] != v[1].second && s[i+1] != v[1].second && v[1].first != v[2].first){
                    pos = i+1;
                    c =  v[1].second;
                    break;
                 }
             }
             if(pos != -1){
                ans.push_back(pos);
                s = s.substr(0,pos) + c + s.substr(pos,s.size() - pos);
                continue;
             }
             
             for(int i = 0;i<s.size()-1;i++){
                 if(s[i] != s[i+1] && s[i] != v[2].second && s[i+1] != v[2].second){
                    pos = i+1;
                    c = v[2].second;
                    break;
                 }
                 else if(s[i] != s[i+1] && s[i] != v[1].second && s[i+1] != v[1].second){
                    pos = i+1;
                    c =  v[1].second;
                    break;
                 }
             }
             if(pos == -1){
                flag = 0;
                break;
             }
              
             ans.push_back(pos);
             s = s.substr(0,pos) + c + s.substr(pos,s.size() - pos);
        }
        if(flag == 0 || ans.size() > 2*n){
            cout<<-1<<endl;
            continue;
        }
        cout<<ans.size()<<endl;

        for(int i = 0;i<ans.size();i++){
            cout<<ans[i]<<endl;
        }
     }
}