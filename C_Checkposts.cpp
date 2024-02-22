#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod  = 1e9+7;

void dfs(ll node,vector<ll> adj[],vector<ll> &vis,stack<ll> &st,ll num){
    vis[node] = 1;

    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,st,num);
        }
    }
    if(num == 1){
      st.push(node);
    }
}
pair<ll,ll>  dfs3(int node,vector<ll>& nums ,  vector<ll> &vis, vector<ll> adjT[]  ) {
        vis[node] = 1;
        ll mn = nums[node] , cnt = 1;
        
        for (auto it : adjT[node]) {
            if (!vis[it]) {
              auto x =   dfs3(it,nums ,  vis, adjT);
              if(x.first < mn)
               {
                   mn = x.first;
                   cnt = x.second;
               }
               else if( x.first == mn){
                   cnt += x.second ;
               }
            }
        }
          return {mn , cnt};
         
    }

int main(){
    ll n;
    cin>>n;
    vector<ll>v(n+1),vis(n+1);
    vector<ll>adj[n+1],tr[n+1];
    map<ll,ll>mp;
    stack<ll> st;
    ll num = 1;

    for(ll i = 1;i<=n;i++){
        cin>>v[i];
    }
    ll m;
    cin>>m;
    while(m--){
        ll l,m;
        cin>>l>>m;
        adj[l].push_back(m);
        tr[m].push_back(l);
    }

    for(ll i = 1;i<= n;i++)
        if(!vis[i]) dfs(i,adj,vis,st,num);

   fill(vis.begin(), vis.end(), 0);
    num = 0;
    long long int ans = 1;
    long long int sum = 0;

    while(!st.empty()){
        ll node = st.top();
        st.pop();
        if(!vis[node]){
              
            auto p = dfs3(node,v,vis,tr);
            sum += p.first;
            ans = ((ans % mod) * (p.second % mod))%mod;
         }
        }
    cout<<sum<<" "<<ans<<endl;
}