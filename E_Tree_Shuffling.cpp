#include<bits/stdc++.h>
using  namespace std;
vector<long long>a(2e5+1),b(2e5+1),c(2e5+1),adj[(int)2e5+1],vis(2e5+1);
long long ans = 0;

vector<int> dfs(int node,long long cost){
     int one = 0;
     int zero = 0;
     vis[node] = 1;

     for(auto it:adj[node]){
         if(!vis[it]){
            vector<int>v = dfs(it,min(cost,c[it]));
            one += v[1];
            zero += v[0];
         }
     }
    if(a[node] != b[node]){
        if(a[node])
          one++;
        else
         zero++;
    }
    int num = min(one,zero);
    ans += 2*num*cost;
   return {zero - num,one - num};
}

int main(){
    int n;
    cin>>n;
    int one = 0,zero = 0;

    for(int i = 1;i<= n;i++){
        cin>>c[i]>>a[i]>>b[i];
        if(a[i] != b[i]){
           if(a[i])
              one++;
            else 
              zero++;
        }
    }
    for(int i = 1;i<= n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(one != zero){
        cout<<"-1";
        return 0;
    }
    dfs(1,c[1]);
    cout<<ans;
}