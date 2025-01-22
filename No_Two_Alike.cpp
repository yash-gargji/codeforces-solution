#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>v;
        map<int,vector<int>>mp;

        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            mp[num].push_back(i);
        }
        for(auto it:mp){
            int k = it.second.size();
            v.push_back({it.second[0],it.second[k-1]});
        } 
        int ans = 0;
        sort(v.begin(),v.end());

        int prev = -1;
        
        for(int i = 0;i<v.size();i++){
            if(v[i][1] - v[i][0] == 0 && prev < v[i][0]){
               prev = v[i][0];
               continue;
            }
            ans++;
            prev = max(prev,v[i][1]);
        }
       cout<<ans<<endl;
    }
} 