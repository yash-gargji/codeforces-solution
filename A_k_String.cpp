#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
     map<char,int>m;
     string s;
     cin>>s;
     for(int i = 0;i<s.size();i++){
        
        m[s[i]]++;
     }
     for(auto it = m.begin(); it != m.end(); it++){
            int num = it->second;
            if(num%n != 0){
                cout<<"-1";
                return 0;
            }
     }
     for(int i = 0;i<n;i++){
         for(auto it = m.begin(); it != m.end(); it++){
            char c = it->first;
            int num = (it->second)/n;

            for(int j = 0;j<num;j++){
                cout<<c;
            }
            
         }
     }
    return 0;
}