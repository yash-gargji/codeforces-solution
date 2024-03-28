#include<bits/stdc++.h>
using namespace std;
    
int main(){
    
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;
        stack<pair<char,int>>st1,st2;

        for(int i = 0;i<s.size();i++){
            if(s[i] == 'b' ){
                 if(!st1.empty())
                    st1.pop();
            }
            else if(s[i] == 'B'){
                if(!st2.empty())
                  st2.pop();
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                st2.push({s[i],i});
            }
            else{
                 st1.push({s[i],i});
            }
        }
       int size = st1.size() + st2.size();
       int ind = size - 1;

       while(!st1.empty() && !st2.empty()){
            auto p = st1.top();
            auto q = st2.top();
            if(p.second > q.second){
                s[ind] = p.first;
                ind--;
                st1.pop();
            }
            else{
                s[ind] = q.first;
                ind--;
                st2.pop();
            }
       }
        while(!st1.empty()){
             auto p = st1.top();
             s[ind] = p.first;
             ind--;
             st1.pop();
       }
        while(!st2.empty()){
             auto p = st2.top();
             s[ind] = p.first;
             ind--;
             st2.pop();
       }

        cout<<s.substr(0,size)<<endl;
    }
  return 0;
} 