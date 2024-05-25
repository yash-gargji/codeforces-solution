#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;

      while(t--){
         int n,x;
         cin>>n>>x;
         int arr[n];

         for(int i = 0;i<n;i++){
             cin>>arr[i];
         }
         priority_queue<int>pq;

         int sum = 0;
         int count = 0;
         for(int i = 0;i<n;i++){
             if(sum >= arr[i]){
               count++;
               sum = sum - arr[i];
               pq.push(arr[i]);
             }
             else if(!pq.empty() && pq.top() >= arr[i]){
                 sum += pq.top() - arr[i];
                 pq.pop();
                 pq.push(arr[i]);
             }
            sum += x;
         }
        cout<<pq.size()<<endl;
      }
}