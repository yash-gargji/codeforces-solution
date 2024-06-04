#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
          int n;
          cin>>n;
          vector<int>v,o;
          map<int,int>mp,has;

          for(int i = 0;i<n;i++){
              int  num;
              cin>>num;
              v.push_back(num);
          }
          
           for(int i = 0;i<n;i++){
              int  num;
              cin>>num;
              o.push_back(num);
              has[o[i]]++;
               if(o[i] != v[i]){
                  mp[o[i]]++;
               }
          }

          int m;
          cin>>m;
          int flag = 1;
          int last_index = 0;

           for(int i = 0;i<m;i++){
              int  num;
              cin>>num;
              if(has.find(num) != has.end()){
                last_index = i+1;
              }
              if(mp.find(num) != mp.end()){
                      mp[num]--;
                      if(mp[num] == 0){
                         mp.erase(num);
                      }
              } 
          }
        if(mp.size() != 0 || last_index < m){
              flag = 0;
        }
        if(flag == 1)
          cout<<"YES\n";
        else{
             cout<<"NO\n";
        }
     }
}