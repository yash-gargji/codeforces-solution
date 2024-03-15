#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>adj(2,vector<int>(n)),vis(2,vector<int>(n)),vis1(2,vector<int>(n));
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,-1,0,1};

        for(int i = 0;i<2;i++){
            for(int j = 0;j<n;j++){
                char c;
                cin>>c;

                if(c == '>'){
                    adj[i][j] = 1;

                }
                else {
                    adj[i][j] = 0;
                }
            } 
        }
        queue<pair<int,int>>q;
        vis[0][0] = 1;
        vis1[0][0] = 1;
        q.push({0,0});

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            for(int i = 0;i<4;i++){
                int row = delrow[i] + p.first;
                int col = delcol[i] + p.second;

                if(row >= 0 && row < 2 && col < n && col >= 0){
                    if(vis[row][col]) continue;
                    vis1[row][col] = 1;
                     vis[row][col] = 1;
                    if(adj[row][col]){
                        col++;
                    }
                    else{
                        col--;
                    }
                    vis1[row][col] = 1;
                    q.push({row,col});
                }
            }
        }
        if(vis1[1][n-1]) cout<<"YES\n";
        else cout<<"NO\n";
      }
    }