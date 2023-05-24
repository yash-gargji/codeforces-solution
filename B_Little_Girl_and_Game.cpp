#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    map<char,int>m;
    for(int i = 0;i<s.size();i++){
        m[s[i]]++;
    }
    int odd = 0;
    int even = 0;
    for(auto &value:m){
        if(value.second %2 == 0){
            even++;
        }
        else{
            odd++;
        }
    }
    int count  = 0;
    
          if(odd){
            count  = odd-1;
          }
    if(count%2 == 0){
        cout<<"First";
    }
    else{
        cout<<"Second";
    }
}