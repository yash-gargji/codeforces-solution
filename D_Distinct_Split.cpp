#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    while(a--){
          int a;
          cin>>a;
          string s;
          cin>>s;
          set<char>s1;
          set<char>s2;
          int r = a;
          s1.insert(s[0]);
          for(int i = 1;i<a;i++){
            int x = s1.size();
            s1.insert(s[i]);
        
             if(x == s1.size()){
                r = i;
                break;
              
             }
            
             
          }
          for(int i = r;i<a;i++){
            s2.insert(s[i]);
          }
          cout<<s1.size()+ s2.size()<<endl;
    }
}