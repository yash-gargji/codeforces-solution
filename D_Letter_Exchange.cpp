#include<bits/stdc++.h>
using namespace std;

void func(string &s){
    string org = "win";
      
      for(int i = 0;i<3;i++){
         for(int j = 0;j<3;j++){
            if(s[j] == org[i] && s[i] != org[i]){
              s[j] = s[i];
              s[i] = org[i];
            }
         }
      }
}

int main(){
    int t;
    cin>>t;

    while(t--){
       int n;
       cin>>n;
       vector<string>v(n);
       map<pair<char,char>,set<int>>m;
       map<char,set<int>>mp;
       vector<vector<int>>ans;
       string org = "win";

       for(int i = 0;i<n;i++){
          string s;
          cin>>s;
          func(s);
          v[i] = s;
          if(s[0] != org[0]){
            m[{org[0],s[0]}].insert(i);
            mp[org[0]].insert(i);
          }
          if(s[1] != org[1]){
            m[{org[1],s[1]}].insert(i);
            mp[org[1]].insert(i);
          }
          if(s[2] != org[2]){
            m[{org[2],s[2]}].insert(i);
             mp[org[2]].insert(i);
          }
       }
       for(int i = n-1;i >= 0;i--){
          if(v[i][0] != org[0] && m[{v[i][0],org[0]}].size() != 0){
            m[{org[0],v[i][0]}].erase(i);
            mp[org[0]].erase(i);
            auto it = m[{v[i][0],org[0]}].rbegin();
            int ind = *it;
            m[{v[i][0],org[0]}].erase(ind);
            mp[v[i][0]].erase(ind);
            ans.push_back({i+1,int(v[i][0]),ind+1,org[0]});
             if(v[i][0] == 'i')
               v[ind][1] = 'i';
             else
              v[ind][2] = 'n';
            v[i][0] = 'w';
          }
          if(v[i][1] != org[1] && m[{v[i][1],org[1]}].size() != 0){
            m[{org[1],v[i][1]}].erase(i);
            mp[org[1]].erase(i);
            auto it = m[{v[i][1],org[1]}].rbegin();
            int ind = *it;
            m[{v[i][1],org[1]}].erase(ind);
            mp[v[i][1]].erase(ind);
            ans.push_back({i+1,int(v[i][1]),ind+1,org[1]});
            if(v[i][1] == 'w')
            v[ind][0] = 'w';
            else
            v[ind][2] = 'n';
            v[i][1] = 'i';
          }
          if(v[i][2] != org[2] && m[{v[i][2],org[2]}].size() != 0){
            m[{org[2],v[i][2]}].erase(i);
            mp[org[2]].erase(i);
            auto it = m[{v[i][2],org[2]}].rbegin();
            int ind = *it;
            m[{v[i][2],org[2]}].erase(ind);
            mp[v[i][2]].erase(ind);
            ans.push_back({i+1,int(v[i][2]),ind+1,org[2]});
            if(v[i][2] == 'w')
               v[ind][0] = 'w';
             else
              v[ind][1] = 'i';
            v[i][2] = 'n';
          }
       }
       while(mp['w'].size() > 0){
          int ind1 = *mp['w'].rbegin();
          int ind2 = *mp['i'].rbegin();
          int ind3 = *mp['n'].rbegin();
          mp['w'].erase(ind1);
          mp['i'].erase(ind2);
          mp['n'].erase(ind3);
          if(v[ind2][1] == 'w' || v[ind2][2] == 'w'){
            ans.push_back({ind1+1,v[ind1][0],ind2+1,'w'});
            ans.push_back({ind2+1,'n',ind3+1,'i'});
          }
          else{
            ans.push_back({ind1+1,v[ind1][0],ind3+1,'w'});
            ans.push_back({ind2+1,'n',ind3+1,'i'});
          }
       }
       cout<<ans.size()<<endl;

       for(int i = 0;i<ans.size();i++){
          char a = ans[i][1];
          char b = ans[i][3];
          cout<<ans[i][0]<<" "<<a<<" "<<ans[i][2]<<" "<<b<<endl;
       }
    }
}