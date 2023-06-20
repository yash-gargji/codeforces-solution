#include<bits/stdc++.h>
using namespace std;
 
int main(){
   int t;
   cin>>t;
   while(t--){
     long long int n;
       cin>>n;
       if(n%2 == 0){
        cout<<n/2<<" "<<n/2<<endl;
       }
       else if(n <= 9){
        cout<<n/2<<" "<<n/2 + 1<<endl;
        continue;
       }
       else{
           int x = n/2;
           int y = n/2 + n%2;
           string s1 = to_string(x);
           string s2 = to_string(y);
           int num = min(s1.size(),s2.size());
             if(s1.size() > s2.size()){
              for(int i = 1;i<s1.size();i++){
                if(s1[i] == '0' && s2[i-1] == '9'){
                  s1[i] = '4';
                  s2[i-1] = '5';
                }
                else if(s1[i] == '9' && s2[i-1] == '0'){
                  s1[i] = '5';
                  s2[i-1] = '4';
                }
              }
             }
              else if(s2.size() > s1.size()){
                 for(int i = 1;i<s2.size();i++){
                if(s2[i] == '0' && s1[i-1] == '9'){
                  s2[i] = '4';
                  s1[i-1] = '5';
                }
                else if(s2[i] == '9' && s1[i-1] == '0'){
                  s2[i] = '5';
                  s1[i-1] = '4';
                }
              }
             }
             else{
                for(int i = 0;i<s2.size();i++){
                if((s2[i] == '0' && s1[i] == '9') ||(s2[i] == '9' && s1[i] == '0') ){
                  if(s1[i-1] < s2[i-1]){
                  s2[i] = '4';
                  s1[i] = '5';
                }
                else{
                   s2[i] = '5';
                  s1[i] = '4';
                }
                }
              }
             }
             cout<<s1<<" "<<s2<<endl;
       }
   }
}