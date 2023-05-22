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
          int count = 0;
          if(s[n-2] == '0'){
            count++;
          }
          for(int i = 0;i<n-1;i++){
            if(s[i] == '1'){
                for(int j = i+1;j<n-1;j++){
                    i = j;
                      if(s[j] == '1'){
                      }
                      else {
                        break;
                      }
                }
                 count++;
            }
          }
          cout<<count<<endl;
    }
    return 0;
}