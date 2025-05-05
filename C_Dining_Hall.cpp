#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
       int n;
       cin>>n;
       int arr[n];

       for(int i = 0;i<n;i++){
           cin>>arr[i];
       }
       priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq,e;

       int count = 0;
       int x = 0;
       int y = 0;
       map<pair<int,int>,int>mp;


       while(count <= n){
           int fact = 3*x + 3*y;
           e.push({fact + 2,3*x + 1,3*y +1 });
           pq.push({fact + 2,3*x + 1,3*y +1 });
           pq.push({fact + 3,3*x + 1,3*y +2 });
           pq.push({fact + 3,3*x + 2,3*y +1 });
           pq.push({fact + 6,3*x + 2,3*y + 2});

           if(y == 0){
              swap(x,y);
              y++;
           }
           else{
             y--;
             x++;
           }
           count++;
       }

       for(int i = 0;i<n;i++){
          pair<int,int>p = {pq.top()[1],pq.top()[2]};
          if(mp.count(p)){
            pq.pop();
            i--;
            continue;
          }
          p = {e.top()[1],e.top()[2]};
          if(mp.count(p)){
            e.pop();
            i--;
            continue;
          }
          vector<int>v;
          if(arr[i] == 0){
              v = e.top();
              e.pop();
          }
          else{
            v = pq.top();
            pq.pop();
          }
          cout<<v[1]<<" "<<v[2]<<endl;
          mp[{v[1],v[2]}] = 1;
       }
       
    }
}