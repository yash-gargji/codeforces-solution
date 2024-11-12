#include<bits/stdc++.h>
using namespace std;

int main(){
     int q;
     cin>>q;
     int h = log2(q)+1;
     vector<vector<int>>up(q+1,vector<int>(h,-1));
     vector<int>cost(q+1),weight(q+1);
     vector<int>child(q+1);
     cin>>weight[0]>>cost[0];
     cout<<endl;

     for(int i = 1;i<= q;i++){
       int num;
       cin>>num;
        if(num == 1){
          int p,a,c;
          cin>>p>>a>>c;
          child[p] = i;
          weight[i] = a;
          cost[i] = c;
          up[i][0] = p;
          for(int j = 1;j<h;j++){
              up[i][j] = up[up[i][j-1]][j-1];
              if(up[i][j] == -1)
                break;
          }
        }
        else{
            int v,w;
            cin>>v>>w;
            long long int ans = 0;
            int x = w;
            while(x > 0){
                int node = v;
                for(int i = h-1;i >= 0;i--){
                    if(up[node][i] == -1 || weight[up[node][i]] == 0)
                    continue;
                    node = up[node][i];
                }
                int k = min(weight[node],x);
                ans += 1ll*cost[node]*k;
                x -= k;
                weight[node] -= k;
                if(node == v)
                    break;
                node = child[node];
                
            }
          cout<<w - x<<" "<<ans;
        }
        cout<<endl;
     }
     
}