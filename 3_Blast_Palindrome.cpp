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

      if(n == 2){
                if(s[0] != s[1]){
                    cout<<"NO\n";
                    continue;
                }
                else{
                    cout<<"YES\n";
                }
            }
            else if(n == 1){
                cout<<"YES\n";
                continue;
            }
        if(n%3 == 1){
            
            cout<<"YES\n";
        }
        else{
            int flag = 0;
           for(int i = 0;i<n/2;i++){
               if(s[i] != s[n-1-i]){
                    flag = 1;
                    break;
               }
           }
           if(flag == 0){
            cout<<"YES\n";
            continue;
           }
           else{
                flag = 0;
             map<char,vector<int>>m;
             for(int i = 0;i<n;i++){
               m[s[i]].push_back(i);
             }
             
             for(auto it = m.begin() ; it != m.end() ;it++){
                   auto v = it->second;
                   int k;
                   int num;
                   for(int i = 0;i<v.size(); i++){
                      if(v[i]%3 == 0 ){
                        k = v[i];
                        for(int j = i+1;j<v.size() ;j++){
                             num = v[j];
                             int p = num - k - 1;
                             if((n - num - 1)%3 == 0 ){
                                if(num - k - 1 == 2 ){
                                    if(s[k+1] == s[num -1]){
                                        flag = 1;
                                        break;
                                    }
                                   
                                }
                                else{
                                      if(p%3 == 1 || p%3 == 0){
                                        flag = 1;
                                        break;
                                      }
                                }
                             }
                        }
                      } 
                      if(flag == 1){
                        break;
                      }    
                   } 
               if(flag == 1){
                    break;
                   }
           }
           if(flag == 1){
                    cout<<"YES\n";
                   }
                   else{
                    cout<<"NO\n";
                   }
        }
        
    }
}
}