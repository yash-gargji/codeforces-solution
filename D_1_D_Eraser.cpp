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
          int k;
          cin>>k;
           string s;
           cin>>s;
           int count = 0;
           for(int i = 0;i<n;i++){
            if(s[i] == 'B'){
                count++;
                i = i + k - 1;
            }
           }
             cout<<count<<endl;
      }
}