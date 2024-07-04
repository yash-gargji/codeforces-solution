#include<bits/stdc++.h>
using namespace std;

 
int main(){
    string s;
    cin>>s;
    map<int,int>m;
    m[0] = 1;
    stack<int>st;
    vector<int>v(s.size());

    for(int i = 0;i<s.size();i++){
        if(s[i] == '('){
           st.push(i);
        }
        else if(!st.empty()){
          int size = i - st.top() + 1;
          v[i] = size;
          if(st.top() > 0){
             v[i] += v[st.top()-1];
          }
          m[v[i]]++;
          st.pop();
        }
    }
    auto it = m.rbegin();
    cout<<it->first<<" "<<it->second;
}