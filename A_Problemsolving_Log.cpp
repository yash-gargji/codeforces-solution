#include<bits/stdc++.h>
using namespace std;

int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
      while(t--){
          int n;
          cin>>n;
          string s;
          cin>>s;
          vector<int>v(26);
           for(int i = 0;i<n;i++){
              v[s[i] - 65]++;
           }
         
           int count = 0;
           for(int i = 0;i<26;i++){
              if(v[i] >= i+1){
                count++;
              }
           }
           cout<<count<<endl;
      }
}