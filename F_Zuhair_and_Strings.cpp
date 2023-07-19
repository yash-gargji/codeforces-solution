#include<bits/stdc++.h>
using namespace std;

int main(){
    
       int n,k;
       cin>>n>>k;

        unordered_map<char,int>m;
        string s;
        cin>>s;
        for(int i = 0;i<n;i++){
             char c = s[i];
             int count = 1;
            for(int j = i+1;j<n;j++){
                if(count == k){
                   break;
                }
                if(s[j] == c){
                     
                    i = j;
                    count++;
                }
                else{
                    break;
                }
            }
            if(count == k){
                m[c]++;
            }
        }
        int ans = 0;
        for(auto it = m.begin(); it != m.end();it++){
            ans = max(ans,it->second);
        }
        cout<<ans;
}