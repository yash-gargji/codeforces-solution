#include<bits/stdc++.h>
using namespace std;

int main(){\

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     int t;
     cin>>t;
     
     while(t--){
         int n;
         cin>>n;
          string s;
          cin>>s;
          int count  = 0;
          for(int i = 0;i<s.size();i++){
            if(s[i] == ':'){
                int flag = 0;
                for(int j = i+1;j<s.size();j++){
                    i = j;
                    if(s[i] == ':'){
                        if(s[i-1] == ':' ){
                              flag = 0;
                        }
                        else{
                             flag = 1;
                        }
                        i = j-1;
                        
                        break;
                    }
                    else if(s[i] == '('){
                         flag = 0;
                         i = j;
                         break;
                    }
                }
                count = count + flag;
            }
          }
          cout<<count<<endl;
     }
}