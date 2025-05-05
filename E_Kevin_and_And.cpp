#include<bits/stdc++.h>
using namespace std;

int main(){
   int t;
   cin>>t;

   while(t--){
       int n,m,k;
       cin>>n>>m>>k;

       long long int sum = 0;
       vector<int>arr(m);
       priority_queue<int>pq;
       
       for(int i = 0;i<n;i++){
           int num;
           cin>>num;
           pq.push(num);
       }
       for(int i = 0;i<m;i++){
           cin>>arr[i];
       }
       while(k > 0 && !pq.empty() && pq.top() > 0){
           int num = pq.top();
           pq.pop();
           int ma = INT_MAX;

           for(int i = 0;i<m;i++){
               ma = min(ma,num & arr[i]);
           }
           if(ma == num){
              sum += num;
           }
           else{
             k--;
             pq.push(ma);
           }
       }
       while(!pq.empty()){
        sum += pq.top();
        pq.pop();
       }
      cout<<sum<<endl;
   }
}