#include<bits/stdc++.h>
using namespace std;

int main(){
     ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
      int t;
      cin>>t;
      
      while(t--){
          string s;
          cin>>s;
             int flag = 1;
             while(flag){
                flag = 0;
          for(int i = 0;i<s.size();i++){
                if(s[i] >= '5'){
                    if(i == 0){
                        flag = 2;
                        break;
                    }
                    else{
                        s[i-1] += 1;
                        flag = 1;
                        for(int j = i;j<s.size();j++){
                             s[j] = '0';
                        }
                        break;
                    }
                }
          }
          if(flag == 2){
            break;
          }
      }
      if(flag == 2){
        cout<<"1";
        for(int i = 0;i<s.size();i++){
              cout<<"0";
        }
        cout<<"\n";
      }
      else{
        cout<<s<<endl;
      }
      }
}