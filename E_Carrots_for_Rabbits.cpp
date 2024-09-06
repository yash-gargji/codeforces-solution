#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int n,k;
    cin>>n>>k;
    priority_queue<long long>pq;
    long long ans = 0;

    for(int i = 0;i<n;i++){
        long long num;
        cin>>num;
        pq.push(num);
    }
    while(pq.size() < k){
       long long a = pq.top();
       pq.pop();
       pq.push(a/2 + a%2);
       pq.push(a/2);
    }
    while(!pq.empty()){
        ans += pq.top()*pq.top();
        pq.pop();
    }
    cout<<ans<<endl;
}