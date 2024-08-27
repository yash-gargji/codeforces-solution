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
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i] - 'a']++;
        }
        int ind = 0;
        while(ind<n){
            vector<int> v; 
            for(auto &it:mp){
                s[ind++] = it.first + 'a';
                it.second--;
                if(it.second == 0){
                    v.push_back(it.first);  
                }
            }
            for(int i = 0;i<v.size();i++){
                mp.erase(v[i]);
            }
        }
        cout<<s<<endl;
    }
    return 0;
}