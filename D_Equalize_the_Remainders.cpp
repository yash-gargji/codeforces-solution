#include<bits/stdc++.h>
using namespace std;

int main(){
   int n,m;
   cin>>n>>m;
   int arr[n];
   vector<vector<int>>v(m);

   for(int i = 0;i<n;i++){
      cin>>arr[i];
      v[arr[i] % m].push_back(i);
    
   }
   queue<int>q;
   long long int ans = 0;
   for(int i = 0;i<m;i++){
      while(v[i].size() > n/m){
          q.push(v[i][v[i].size()-1]);
          v[i].pop_back();
      }
      while(v[i].size() < n/m && !q.empty()){
          int ind = q.front();
          q.pop();
          // cout<<arr[ind]<<" "<<i<<endl;
          v[i].push_back(ind);
          int num = arr[ind] % m;
          if(num > i){
            ans += m-num + i;
              arr[ind] += m-num + i;
          }
          else{
            ans += i - num;
            arr[ind] += i - num;
          }
      }
   }
   for(int i = 0;i<m;i++){
      while(v[i].size() > n/m){
          q.push(v[i][v[i].size()-1]);
          v[i].pop_back();
      }
      while(v[i].size() < n/m && !q.empty()){
          int ind = q.front();
          q.pop();
          v[i].push_back(ind);
          int num = arr[ind] % m;
          if(num > i){
            ans += m-num + i;
              arr[ind] += m-num + i;
          }
          else{
            ans += i - num;
            arr[ind] += i - num;
          }
      }
   }
   cout<<ans<<endl;
   for(int i = 0;i<n;i++){
     cout<<arr[i] << " ";
   }
}