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
        vector<int>o,z;
        if(n == 1 && s[0] == '0'){
          cout<<"1\n";
          continue;
        }

        for(int i = 0;i<n;i++){
            if(s[i] == '0'){
              int count = 1;
              for(int j = i+1;j<n;j++){
                if(s[j] == '0'){
                   i = j;
                   count++;
                }
                else{
                    break;
                }
              }
              z.push_back(count);
            }
            else{
                int count = 1;
                for(int j = i+1;j<n;j++){
                    if(s[j] == '1'){
                    i = j;
                    count++;
                    }
                    else{
                        break;
                    }
                }
              o.push_back(count);
            }
        }
        
       if(o.size() > z.size()){  
          cout<<"0\n";
       }
       else if(o.size() == z.size()){
            cout<<"1\n";
        }
        else{
             cout<<"2\n";
        }
       
    }
}