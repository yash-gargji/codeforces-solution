#include<bits/stdc++.h>
using namespace std;

int main(){

     
    string s;
    cin>>s;
    int count = 0;
   if(s.size() == 1){
    cout<<0;
    return 0;
   }
    for(int i =s.size()-1;i>= 0;i--){
       if(s[i] == '1'){
        count++;
       }
    }
  if(s.size()%2 == 0){
    cout<<s.size()/2;
  }  
  else{
    if(count == 1){
        cout<<s.size()/2;
    }
    else{
        cout<<s.size()/2+1;
    }
  }
}