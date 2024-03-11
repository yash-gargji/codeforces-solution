#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>adj[n+1];
        vector<int>indegree(n+1),vis(n+1);

        for(int i = 0;i<n-1;i++){
             int u,v;
             cin>>u>>v;
             adj[u].push_back(v);
             adj[v].push_back(u);
             indegree[u]++;
             indegree[v]++;
        }
        if(k >= n) {
          cout<<"0\n";
          continue;
        }
        queue<int>st;
        int count = 0;
    
        for(int i = 0 ;i<=n;i++){
            if(indegree[i] == 1) st.push(i);
              vis[i] = 1;
        }

        while(!st.empty() && k--){
            int size = st.size();
            count += size;

            for(int i = 0;i<size;i++){
                 int node = st.front();
                 st.pop();
                 for(auto it : adj[node]){
                     if(indegree[it] != 1){
                        indegree[it]--;
                      if(indegree[it] == 1){
                        st.push(it);
                      } 
                  }
                 } 
            }
        }
        cout<<n - count<<endl;
    }
}