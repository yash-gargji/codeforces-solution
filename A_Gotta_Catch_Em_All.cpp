#include<bits/stdc++.h>
using namespace std;

int main(){
     
    
      string s;
      cin>>s;
      int ans = 100001;
      map<char,int>m1;
      string a  = "Bulbbasaur";
      for(int i = 0;i<a.size();i++){
        m1[a[i]] = 0;
      }
      for(int i = 0;i<s.size();i++){
         if(m1.find(s[i]) == m1.end()){
            continue;
         }
         m1[s[i]]++;
      }
       int ans1 = 100001,ans2 = 1000001;
       for(int i = 0;i<a.size();i++){
            if(a[i] == 'u' || a[i] == 'a'){
                ans2 = min(ans2,m1[a[i]]);
            }
            else{
                ans1 = min(ans1,m1[a[i]]);
            }
       }
       cout<<min(ans1,ans2/2);
}