#include<bits/stdc++.h>
using namespace std;

int dfs(int node,vector<int>&arr,string &s,vector<int>&vis){
    if(vis[node-1] != -1)
      return vis[node - 1];
    if(arr[node-1] == node){
       if(s[node-1] =='0'){
         return vis[node - 1] = 1;
       }
       else{
        return vis[node-1] = 0;
       }
    }
    vis[node - 1] = 0 ; 
    return vis[node - 1] = (s[node - 1] =='0' ? 1 : 0) + dfs(arr[node-1],arr,s,vis);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
         vector<int>arr(n);
        vector<int>vis(n,-1);

        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
         string s;
        cin>>s;
        for(int i = 0;i<n;i++){
            cout<<dfs(i+1,arr,s,vis)<<" ";
        }
        cout<<endl;
    }
}