#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int ans = 0;
        vector<int>v(26);
        string s;
        cin>>s;

        for(int i = 0;i<s.size();i++){
             if(s[i] == '?')
               continue;
            v[s[i] - 'A']++;
        }
        for(int i = 0;i<26;i++){
            ans += min(v[i],n);
        }
      cout<<ans<<endl;
    }
}