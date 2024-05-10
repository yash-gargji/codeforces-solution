#include<bits/stdc++.h>
using namespace std;

long long gcd(long long int a, long long int b) 
{ 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
} 
int vis[101][101];
void dfs(int row,int col,int fact,vector<vector<int>>&grid){
       vis[row][col] = fact;

       if(row + 1 < grid.size() && vis[row+1][col] != fact && grid[row+1][col] % fact == 0){
           dfs(row+1,col,fact,grid);
             
       }
       if(col + 1 < grid[0].size() && vis[row][col+1]  != fact && grid[row][col+1] % fact == 0){
          dfs(row,col+1,fact,grid);
       }
      
}

int main(){
     ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
      while(t--){
        memset(vis, 0, sizeof(vis));
         int n,m;
         cin>>n>>m;
         vector<vector<int>>grid(n,vector<int>(m));
         vector<int>fact;
         for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>grid[i][j];
            }
         }
         int num = (int)gcd(grid[n-1][m-1],grid[0][0]);
         if(num == 1){
            cout<<1<<endl;
             continue;
         }
         for(int i = 1;i*i <= num;i++){
             if(num % i == 0){
                fact.push_back(i);
                if(num/i != i){
                 fact.push_back(num/i);
               }
             }
         } 
         sort(fact.begin(),fact.end());
        for(int i = fact.size() - 1;i >= 0;i--){
              vis[0][0] = fact[i];
              dfs(0,0,fact[i],grid);
             if(vis[n-1][m-1] == fact[i]){
                 cout<<fact[i]<<endl;
                 break;
             }
        }
    }
}