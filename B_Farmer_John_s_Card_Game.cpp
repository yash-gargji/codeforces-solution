#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n,m;
        cin>>n>>m;
        vector<vector<int>>v(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
            sort(v[i].begin(),v[i].end());
        }
        vector<pair<int,int>>t;
        for(int i=0;i<n;i++){
            t.push_back({v[i][0],i});
        }
        sort(t.begin(),t.end());
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(t[i].second);
        }
        vector<int>f;
        for(int i=0;i<m;i++){
            for(auto ind:ans){
                f.push_back(v[ind][i]);
            }
        }
        int flag = 1;
        for(int i=0;i<n*m;i++){
            if(f[i]!=i){
                flag = 0;
            }
        }
        if(flag){
            for(int i=0;i<n;i++){
                cout<<ans[i]+1<<" ";
            }
             cout<<endl;
             continue;
        }
        cout<<"-1"<<endl;
    }
}