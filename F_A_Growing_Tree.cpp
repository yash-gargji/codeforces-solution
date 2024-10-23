#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;

     while(t--){
         int q;
         cin>>q;
         unordered_map<int,vector<int>>adj;
         int num = 2;
         map<int,long long>ans;

         for(int i = 0;i<q;i++){
             int x;
             cin>>x;
             if(x == 1){
                int v;
                cin>>v;
                adj[num].push_back(v);
                adj[v].push_back(num);
                num++;
             }
             else{
                int v,num;
                cin>>v>>num;
                ans[v] += num;
             }
         }
         queue<vector<long long>>v;
         v.push({ans[1],1,-1});

         while(!v.empty()){
            auto vec = v.front();
            v.pop();
           for(auto it:adj[vec[1]]){
               if(it != vec[2]){
                  ans[it] += vec[0];
                  v.push({ans[it],it,vec[1]});
               }
           }
         }
         for(auto it:ans){
           cout<<it.second<<" ";
         }
         cout<<endl;
     }
}