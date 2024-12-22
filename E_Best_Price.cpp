#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
       int n,k;
       cin>>n>>k;
       int a[n],b[n];
       vector<vector<int>>v(n,vector<int>(2));
       long long ans = 0;

       for(int i = 0;i<n;i++){
          cin>>a[i];
          v[i][0] = a[i];
       }
       for(int i = 0;i<n;i++){
          cin>>b[i];
          v[i][1] = b[i];
       }
       sort(v.begin(),v.end());
       priority_queue<int,vector<int>,greater<int>>pq;
       
       for(int i = 0;i<n;i++){
           pq.push(b[i]);
       }

       for(int i = k;i<n;i++){
           while(!pq.empty() && pq.top() < v[i][0]){
               int prev = pq.top();
               if(pq.size() > k + n - i)
                while(pq.top() == prev)
                    pq.pop();
                if(pq.size() <= k + n - i)
                  ans = max(ans,(long long)pq.size() * pq.top());
                pq.pop();
           }
           if(pq.top() >= v[i][0] && pq.size() > k + n - i){
              i++;
              continue;
           }
           if(pq.size() <= k + n - i)
             ans = max(ans,(long long)pq.size()*v[i][0]); 
       }
       while(!pq.empty()){
           if(pq.size() <= k)
             ans = max(ans,(long long)pq.size() * pq.top());
            else {
              int prev = pq.top();
              while(!pq.empty() && prev == pq.top())
                pq.pop();
              continue;
            }
           pq.pop();
       }
       cout<<ans<<endl;
    }
}