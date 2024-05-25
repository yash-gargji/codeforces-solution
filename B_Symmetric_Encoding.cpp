#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
           int n;
           cin>>n;
            string s;
            cin>>s;

            set<char>st;

            for(int i = 0;i<n;i++){
                 st.insert(s[i]);
            }
          vector<char>v;

          for(auto it:st){
             v.push_back(it);
          }
           map<char,char>m;

          for(int i = 0;i<v.size();i++){
              m[v[i]] = v[v.size() - 1 - i]; 
               
          }
          cout<<" ";
         for(int i = 0;i<n;i++){
             s[i] = m[s[i]];
         }
        cout<<s<<endl;
     }
}