#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;

     while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<pair<int,int>>v(n);
        int ans = 0;

        for(int i = 0;i<n;i++){
            cin>>v[i].first>>v[i].second;
        }
        vector<pair<int,int>>q;

        for(int i = 0;i<n;i++){
            int limit = (i < n-1 ? min(v[i+1].first,v[i].first + k) : 1e9);
            q.push_back(v[i]);
            int sum = 0;
            int curr = v[i].first;
            while(!q.empty() && q.back().first + k - 1 >= curr && curr < limit){
                 int d = (sum + q.back().second)/m;
                 d = min({d,q.back().first + k - curr,limit - curr});
                 ans += d;
                 curr += d;
                 q.back().second = q.back().second + sum - d * m;
                 if(curr <  limit){
                    sum = q.back().second;
                    q.pop_back();
                 }   
            }
        }
       cout<<ans<<endl;
     }
}