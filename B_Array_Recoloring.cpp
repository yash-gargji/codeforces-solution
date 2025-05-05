#include<bits/stdc++.h>
using namespace std;
#define int long long

int func(int ind,vector<int>&arr,int k){
   int count = k-2;
    priority_queue<int>pq1,pq2;

    for(int i = 0;i<ind;i++){
        pq1.push(arr[i]);
    }
    for(int i = ind + 1;i<arr.size();i++){
        pq2.push(arr[i]);
    }
   int c = pq1.top() + pq2.top() + arr[ind];
    pq1.pop();
    pq2.pop();

    while(count > 0 && !pq1.empty() && !pq2.empty()){
        if(pq1.top() >= pq2.top()){
            c += pq1.top();
            pq1.pop();
            count--;
        }
        else{
            c += pq2.top();
            pq2.pop();
            count--;
        }
    }
    while(count > 0 && !pq1.empty()){
        c += pq1.top();
        pq1.pop();
        count--;
    }
    while(count > 0 && !pq2.empty()){
        c += pq2.top();
        pq2.pop();
        count--;
    }
  return c;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);

        for(int i = 0;i<n;i++){
           cin>>arr[i];
        }

        int ans = 0;
        int a = arr[0];
        int b = arr[n-1];

        priority_queue<int>pq;

        for(int i = 1;i<n;i++){
            pq.push(arr[i]);
        }
        int count = k;
        while(!pq.empty()){
            if(count > 0){
                count--;
                a += pq.top();
            }
            pq.pop();
        }
        ans = max(ans,a);
        for(int i = 0;i<n-1;i++){
            pq.push(arr[i]);
        }
        count = k;
        while(!pq.empty()){
            if(count > 0){
                count--;
                b += pq.top();
            }
            pq.pop();
        }
        ans = max(ans,b);

        if(k >= 2 ){
           for(int i = 1;i<n-1;i++){
              ans = max(ans,func(i,arr,k));
           }
        }
        cout<<ans<<endl;
        
    }
}