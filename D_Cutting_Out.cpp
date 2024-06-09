#include<bits/stdc++.h>
using namespace std;

int main(){
     int n,k;
     cin>>n>>k;
     unordered_map<int,int>freq,m;
     map<int,int>mp;
     vector<pair<int,int>>v;
     priority_queue<pair<int,int>>pq;

     for(int i = 0;i<n;i++){
         int num;
         cin>>num;
         freq[num]++;
     }
     for(auto it:freq){
         v.push_back({it.second,it.first});
     }
     sort(v.begin(),v.end());
     int ind = v.size() -1;
     int count = 0;

     while(ind >=0 && count < k){
          m[v[ind].second] = 1;
          count++;
          pq.push({v[ind].first,v[ind].second});
          mp[v[ind].first]++;
          ind--;  
     }
     ind++;
     int ans = v[ind].first;
    int number = v[ind].second;
     while(count <  k){
         m[pq.top().second]++;
         int num = pq.top().first/m[pq.top().second];
         ans = min(ans,num);
         pq.push({num,pq.top().second});
     }
}