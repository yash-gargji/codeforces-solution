#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
       map<char,int>m1,m2;
       for(int i = 0;i<a.size();i++){
            m1[a[i]]++;
       }
        for(int i = 0;i<b.size();i++){
            m2[b[i]]++;
       }
       int flag = 1;
      for(auto it = m2.begin(); it != m2.end();it++){
           char c = it->first;
           auto itr = m1.find(c);
           if(itr == m1.end()){
            flag = 0;
            break;
           }
           if(it->second > itr->second ){
            flag = 0;
            break;
           }
      }
       if(flag == 0 || a.size() < b.size()){
        cout<<"need tree";
        return 0;
       }
       else if(a.size() == b.size()){
        cout<<"array";
        return 0;
       }
       flag = 0;
       int j = 0;
       for(int i = 0;i<a.size();i++){
        if(j == b.size()- 1){
            flag = 1;
            break;
        }
        if(a[i] == b[j]){
            j++;
        }
       }
       if(flag == 1){
        cout<<"automaton";
       }
       else{
        cout<<"both";
       }
}