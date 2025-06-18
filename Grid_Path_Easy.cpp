#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int qu;
        cin>>qu;
        vector<string>v(2);
        cin>>v[0]>>v[1];

        vector<vector<int>>grid(2,vector<int>(n,1e18));

        queue<int>q;
        int sum = 0;

        for(int i = 0;i<n;i++){
           q.push(i);
           if(v[0][i] == '1'){
              sum += i - q.front();
              grid[0][q.front()] = sum;
              q.pop();
            }
        }
        while(!q.empty()){
            q.pop();
        }
        sum = 0;
        for(int i = n-1;i >= 0;i--){
           q.push(i);
           if(v[1][i] == '1'){
              sum += q.front() - i;
              grid[1][q.front()] = sum;
              q.pop();
           }
        }
        int ans = 1e18;
        
        for(int i = 0;i<n;i++){
           if(grid[0][i] != 1e18 && grid[1][i] != 1e18){
              ans = min(ans,grid[0][i] + grid[1][i]);
           } 
        }
      cout<<(ans == 1e18 ? -1 : ans)<<endl;
    }
} 