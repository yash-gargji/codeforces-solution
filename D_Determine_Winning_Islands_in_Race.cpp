#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>>v(m);
        vector<int>dis(n+1);
        
        for(int i = 1;i<= n;i++){
            dis[i] = i-1;
        }

        for(int i = 0;i<m;i++){
            int u,vi;
            cin>>u>>vi;
            v[i].first = min(u,vi);
            v[i].second = max(u,vi);
        }
        int ind = 0;
        sort(v.begin(),v.end());
        priority_queue<int>pq;

        for(int i = 1;i<n;i++){
            int flag = 1;
            dis[i] = min(dis[i],dis[i-1] + 1);
           while(ind < m && v[ind].first < i){
                if(dis[v[ind].second] > dis[v[ind].first] + 1){
                   dis[v[ind].second] = dis[v[ind].first] + 1;
                   pq.push(v[ind].second - dis[v[ind].second]);
                }
                ind++;
           }
           if(!pq.empty() && pq.top() > i){
              flag = 0;
           }
           cout<<flag;
        }
       cout<<endl;
    }
    
}