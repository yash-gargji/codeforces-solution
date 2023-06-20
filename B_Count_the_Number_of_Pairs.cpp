#include<bits/stdc++.h>
using namespace std;

int main(){
          int t;
          cin>>t;
          while(t--){
            int n;
            cin>>n;
            int k;
            cin>>k;
            string s;
            cin>>s;
              map<char,int>m1,m2;
              char c = 'a';
              for(int i = 0;i<26;i++){
                       m1[c+i] = 0;
              }
              c = 'A';
               for(int i = 0;i<26;i++){
                       m2[c+i] = 0;
              }
              for(int i = 0;i<n;i++){
                   if(s[i] >= 'A' && s[i] <= 'Z'){
                          m2[s[i]]++;
                   }
                   else{
                        m1[s[i]]++;
                   }
              }
              int ans = 0;
              int pair = 0;
              for(int i = 0;i<26;i++){
                   int x = m1[c+i + 32];
                   int y =  m2[c+i];
                  ans = ans + min(x,y);
                   pair = pair + (max(x,y) - min(x,y))/2;
              }
               if(pair <= k){
                cout<<ans + pair<<endl;
               }
               else{
                cout<<ans+k<<endl;
               }
       }
       return 0;
}