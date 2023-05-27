#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      string s;
      cin>>s;
      int ans = 0;
      for(int i = 0;i<n;i++){
         int count = 1;
         char c;
         if(s[i] == '>'){
             c = '>';
             
         }
         else {
            c = '<';
         }
          for(int j = i +1;j<n;j++){
                if(s[j] == c){
                    count++;
                    i = j;
                }
                else {
                    break;
                }
             }
             ans = max(ans,count);
      }
      cout<<ans+1<<endl;
    }
    return 0;
}