#include<bits/stdc++.h>
using namespace std;

int main(){
      
         int n;
         cin>>n;
         long long sum = 0;
         int count = 0;

         priority_queue<int>pq;

         for(int i = 0;i<n;i++){
             int num;
             cin>>num;
             if(num >=0 ){
                 count++;
                 sum += num;
             }
               
              else {
                 if(sum >= abs(num)){
                    count++;
                    sum += num;
                    pq.push(abs(num));
                 }
                 else if(!pq.empty() && pq.top() >  abs(num)){
                      sum += pq.top() - abs(num);
                        pq.pop();
                      pq.push(abs(num));
                 }
              }
         }
        cout<<count<<endl;
     
}