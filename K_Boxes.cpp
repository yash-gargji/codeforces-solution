#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;

        vector<vector<int>>v(n,vector<int>(3));

        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            v[i][0] = num;
        }
        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            v[i][1] = num;
            v[i][2] = i;
        }
        sort(v.begin(),v.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        int sum = 0;
        vector<int>ans(n);

        for(int i = 0;i<n;i++){
            ans[v[i][2]] = sum;
            if(pq.size() < k){
               sum += v[i][1];
               pq.push(v[i][1]);
               continue;
            }
            if(pq.top() < v[i][1]){
               sum -= pq.top();
               pq.pop();
               sum += v[i][1];
               pq.push(v[i][1]);
            }
        }

        for(int i = 0;i<n;i++){
           cout<<ans[i]<<" ";
        }

        cout<<endl;
        
    }
}