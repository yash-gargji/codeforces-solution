#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;

     while(t--){
         int n,m,k;
         cin>>n>>m>>k;
         long long ans = 0;
         map<int,map<int,int>>mp;
         map<int,int>p,nge;
         stack<pair<int,int>>st;
         int prev = 0;
         int prev_row = 0;
         mp[1][-1] = -1;
         mp[1][0] = k;
         mp[m][1] = k+1;

         for(int i = 0;i<k;i++){
             int num1,num2;
             cin>>num1>>num2;
             mp[num2][num1] = i;
             mp[num2][0] = -1;
         }
         for(auto it:mp){
             ans += 1ll*(it.first - prev_row - 1)*(n - prev);
             prev_row = it.first;
             auto itr = it.second.end();
             itr--;
             int mn = min(n - itr->first,n - prev);
             ans += mn;
             while(!st.empty() && st.top().first < itr->first){
                 nge[st.top().second] = it.first;
                 st.pop();
             }
             auto lop = itr;
             itr--;
             st.push({max(prev,(itr->first)),it.first});
             p[it.first] = prev;
             prev = max(prev,lop->first);
         }
        while(!st.empty()){
              nge[st.top().second] = m+1;
              st.pop();
         }
          vector<long long>v(k+2);
        for(auto it:mp){
            auto itr = it.second.end();
            itr--;
             if(p[it.first] >=  itr->first)
               continue;
            auto lop = itr;
            itr--;
            long long num = max(p[it.first],itr->first);
            num = 1ll*(nge[it.first] - it.first)*(lop->first - num);
            v[lop->second] = num;
        }

         cout<<ans<<endl;
         for(int i = 0;i<k;i++){
             cout<<v[i]<<" ";
         }
        cout<<endl;
     }
}