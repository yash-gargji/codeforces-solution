#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>vis(26,-1);

    for(int i = n-1;i>=0;i--){
        if(vis[s[i] - 'a'] == -1){
           vis[s[i] - 'a'] = i; 
        }
    }
    vector<int>v(n,-1);
    int flag = 0;

    for(int i = 0;i<n;i++){
        int prev = v[i];
        if(v[i] != -1)
          prev = !prev;
        for(int j = i+1;j<vis[s[i] - 'a'];j++){
            if(s[j] == s[i]){
               if(prev != -1){
                  v[j] = !prev;
               }
               continue;
            }
            if(v[j] != -1){
              if(prev == -1)
                prev = v[j];
              else if(prev != v[j]){
                  flag = 1;
                  break;
              }
            }
            else{
                if(prev == -1){
                    prev = 1;
                    v[j] = 1;
                }
                else{
                    v[j] = prev;
                }
            }
        } 
    }
    if(flag)
      cout<<"NO";
    else{
        cout<<"YES\n";
        for(int i = 0;i<n;i++){
            if(v[i] == -1){
               cout<<0;
            }
            else
             cout<<v[i];
        }
    }
}