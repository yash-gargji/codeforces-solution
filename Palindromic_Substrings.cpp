#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         int a = 0;
         int b = 0;
         string s;
         cin>>s;
         int count = 0;
         if(n <= 2){
             cout<<"Bob\n";
             continue;
         }
         vector<int>v;
       for(int i= 0;i<s.size();i++){
            if(s[i] == '0'){
                int k = 1;
                  for(int j = i+1; j<s.size();j++){
                      if(s[j] == s[i]){
                          i = j;
                          k++;
                      }
                      else{
                        break;
                      }
                  }
                  a++;
                  count += k-1;
                  v.push_back(k);
            }
            else {
                int k = 1;
                  for(int j = i+1; j<s.size();j++){
                      if(s[j] == s[i]){
                          i = j;
                          k++;
                      }
                      else{
                        break;
                      }
                  }
                  b++;
                  count += k-1;
                   v.push_back(k);
            }
       }
       if(a == 0 || b == 0){
             if(count%2){
                 cout<<"Bob\n";
             }
             else{
                cout<<"Alice\n";
             }
             continue;
       }
       if(s[0] == s[s.size() - 1]){
          count++;
          if(s[0] == '0'){
              a--;
          }
          else {
            b--;
          }
       }
       if(a == 1 && b == 1 && (v[0] == 1 || v[v.size() - 1] ==1)){
             cout<<"Alice\n";
       }
       else if(count%2 == 0 && count != 0){
             if((a+b) % 2 == 0){
                  cout<<"Alice\n";
             }
             else{
                cout<<"Bob\n";
             }
       }
       else{
             if((a+b) % 2 == 1){
                  cout<<"Alice\n";
             }
             else{
                cout<<"Bob\n";
             }
       }
    }
}