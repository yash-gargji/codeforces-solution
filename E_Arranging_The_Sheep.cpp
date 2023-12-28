#include<bits/stdc++.h>;
using namespace std;

int main(){
      int t;
      cin>>t;

      while(t--){

            long long  int n;
            string s;
            cin>>n>>s;
      
            vector<long long int>v1(n),v2(n);
            long long int  count = 0;
               v1[0] = 0;
               v2[n-1] = 0;
               if(s[0] == '*'){
                  count = 1;
               }
             for(int i = 1;i<n;i++){
                 if(s[i] == '*'){
                       count++;
                       v1[i] = v1[i-1];
                } 
                else {
                      v1[i] = v1[i-1] + count;
                }
             } 
             count = 0;
               if(s[n-1] == '*'){
                  count = 1;
               }
              for(int i = n-2;i > -1;i--){
                  if(s[i] == '*'){
                       count++;     
                      v2[i] = v2[i+1];
                } 
                else {
                      v2[i] = v2[i+1] + count;
                }
             }
              
             long long int ans = min(v1[n-1],v2[0]);
                 
                 for(int i = 0;i<v1.size()-1;i++){
                     ans  = min(ans,v1[i]+v2[i+1]);
                 }
             cout<<ans<<endl;
      }
}