#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<int>vis(n+1,0);
        map<int,int>vi;
        
        for(int i = 1;i<=n;i++){
           int num;
           cin>>num;
           if(num != 0){
              vi[num] = i;
              vis[i] = num;
           }
        }
        int sum = 0;
        vector<int>pre(n+1);
        for(int i = 1;i<n+1;i++){
            pre[i] = sum;
            sum += !vi.count(i);
        }
        vector<int>adj[n+1];

        for(int i = 0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<pair<int,int>>p;
        
        for(int i = 1;i <= n;i++){
            if(vis[i] == 0){
               int count = 0;
               int ma = 0;
               for(auto it:adj[i]){
                  if(vis[it] == 0){
                     count++;
                  }
                  ma = max(ma,vis[it]);
               }
                //cout<<ma<<" "<<count<<endl;
               p.push_back({ma,count});
            }
        }
        int m = p.size();
        sort(p.begin(),p.end());
        
        int mi = INT_MAX;
        int ind = 0;

        int ans = n;

        for(int i = 1;i<= n;i++){
            if(vi.count(i) == 1){
               int node = vi[i];
               int fl = 0;
               int count = 0;
               for(auto it:adj[node]){
                  fl = max(fl,vis[it]);
                  count += (vis[it] == 0);
               }
               if(fl < i && count <= pre[i]){
                 ans = i;
                 break;
               }
            }
            else{
               while(ind < p.size() && p[ind].first < i){
                     mi = min(mi,p[ind].second);
                    ind++;
                //    cout<<mi<<endl;
               }
               if(mi <= pre[i]){
                  ans = i;
                  break;
               }
            }
        }
        cout<<ans<<endl;
        
    }
}