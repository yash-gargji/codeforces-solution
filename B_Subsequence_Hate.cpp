#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<int>v(3);
        int flag  = 0;
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '1'){
            for(int j = i;j<s.size();j++){
                if(s[j] != '1'){
                    break;
                }
                else {
                    i = j;
                       if(v[0] == 0){
                        v[0]++;
                       }
                       else if(v[1] == 0){
                        v[1]++;
                       }
                       else{
                        v[2]++;
                       }
                }
            }
            sort(v.begin(),v.end());
            ans = ans +v[0];
              if(v[0] != 0){
                 v[2] = v[0] + v[1];
                   v[1] = 0;
               }
                 v[0] = 0;
             }

        else{
              for(int j = i;j<s.size();j++){
                if(s[j] != '0'){
                    break;
                }
                else {
                    i = j;
                       if(v[0] == 0){
                        v[0]++;
                       }
                       else if(v[1] == 0){
                        v[1]++;
                       }
                       else{
                        v[2]++;
                       }
                }
            }
             sort(v.begin(),v.end());
            ans = ans +v[0];
              if(v[0] != 0){
                 v[2] = v[0] + v[1];
                   v[1] = 0;
               }
                 v[0] = 0;
                }
        }
        cout<<ans<<endl;
    }
    return 0;
}